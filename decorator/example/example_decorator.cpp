#include "../decorator.h"

int main() {
    using design_pattern::decorator::Component;
    using design_pattern::decorator::ConcreteComponent;
    using design_pattern::decorator::Decorator;

    ConcreteComponent last("last");

    //dynamically add decorator
    Decorator second(last, "second");
    Decorator first(second, "first");

    //call operation for all children
    first.Operation();

    return 0;
}


