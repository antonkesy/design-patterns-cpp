#include "../composite.h"

namespace design_pattern::composite_design_pattern {

    int example_usage() {
        Composite bike;

        Leaf front_wheel("front_wheel");
        Leaf back_wheel("back_wheel");

        //dynamically add components to bike
        //leaves
        bike.Add(&front_wheel);
        bike.Add(&back_wheel);

        //or complete composites
        Leaf cassette("cassette");
        Composite gearing;
        gearing.Add(&cassette);

        bike.Add(&gearing);

        //call operation for all children
        bike.Operation();
        std::cout << std::endl;

        //remove components dynamically
        bike.Remove(&front_wheel);

        bike.Operation();
        std::cout << std::endl;

        //get child by index
        Component *child = bike.GetChild(0);
        bike.Remove(child);

        bike.Operation();
        std::cout << std::endl;


        try {
            //throw exception when leaf is called with composite only function
            back_wheel.GetChild(0);
        }
        catch (std::invalid_argument &) {
            std::cout << "invalid argument!" << std::endl;
        }
        return 0;
    }

}

int main() {
    return design_pattern::composite_design_pattern::example_usage();
}


