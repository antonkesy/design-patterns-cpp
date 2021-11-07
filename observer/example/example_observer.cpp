#include "../observer.h"

namespace design_pattern::observer
{
    int example_usage()
    {
        ConcreteObserver observer1(1);
        ConcreteObserver observer2(2);
        ConcreteObserver observer3(3);
        Subject subject;

        //nothing gets updated -> nothing observes
        subject.Notify();

        subject.Attach(&observer1);
        subject.Attach(&observer2);

        //updates 2
        subject.Notify();
        std::cout << std::endl;

        subject.Attach(&observer3);

        //all 3 observer get updated
        subject.Notify();
        std::cout << std::endl;

        subject.Detach(&observer1);
        //updates only 2-3
        subject.Notify();

        return 0;
    }

}

int main()
{
    return design_pattern::observer::example_usage();
}


