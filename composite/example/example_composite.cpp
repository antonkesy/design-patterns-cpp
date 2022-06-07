#include "../composite.h"


int main() {
    using design_pattern::composite::Composite;
    using design_pattern::composite::Leaf;

    Composite bike;

    auto front_wheel = std::make_shared<Leaf>("front_wheel");
    auto back_wheel = std::make_shared<Leaf>("back_wheel");

    //dynamically add components to bike
    //leaves
    bike.Add(front_wheel);
    bike.Add(back_wheel);

    //or complete composites
    auto cassette = std::make_shared<Leaf>("cassette");
    auto gearing = std::make_shared<Composite>();
    gearing->Add(cassette);

    bike.Add(gearing);

    //call operation for all children
    bike.Operation();
    std::cout << std::endl;

    //remove components dynamically
    bike.Remove(front_wheel);

    bike.Operation();
    std::cout << std::endl;

    //get child by index
    auto child = bike.GetChild(0);
    bike.Remove(child);

    bike.Operation();
    std::cout << std::endl;


    try {
        //throw exception when leaf is called with composite only function
        back_wheel->GetChild(0);
    }
    catch (std::invalid_argument &) {
        std::cout << "invalid argument!" << std::endl;
    }

    return 0;
}


