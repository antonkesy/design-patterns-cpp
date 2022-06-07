#include "../factory_method.h"

int main() {
    using design_pattern::factory_method::ConcreteCreator;
    using design_pattern::factory_method::Product;

    ConcreteCreator creator;
    auto p = creator.FactoryMethod();
    p->PrintValue();

    return 0;
}