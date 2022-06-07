#include "../prototype.h"

int main() {
    using design_pattern::prototype::Client;
    using design_pattern::prototype::ConcretePrototype1;
    using design_pattern::prototype::ConcretePrototype2;

    ConcretePrototype1 prototype1;
    Client c(prototype1);
    c.Operation();

    ConcretePrototype2 prototype2;
    Client c2(prototype2);
    c2.Operation();

    return 0;
}