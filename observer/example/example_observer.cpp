#include "../observer.h"

int main() {
    using design_pattern::observer::ConcreteObserver;
    using design_pattern::observer::Subject;

    auto observer1 = std::make_shared<ConcreteObserver>(1);
    auto observer2 = std::make_shared<ConcreteObserver>(2);
    auto observer3 = std::make_shared<ConcreteObserver>(3);
    Subject subject;

    //nothing gets updated -> nothing observes
    subject.Notify();

    subject.Attach(observer1);
    subject.Attach(observer2);

    //updates 2
    subject.Notify();
    std::cout << std::endl;

    subject.Attach(observer3);

    //all 3 observer get updated
    subject.Notify();
    std::cout << std::endl;

    subject.Detach(observer1);
    //updates only 2-3
    subject.Notify();

    return 0;
}