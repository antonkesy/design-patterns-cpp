#include "../abstract_factory.h"

int main() {
    using design_pattern::abstract_factory::Client;

    Client c(true);

    auto pa = c.CreateProductA();
    auto pb = c.CreateProductB();

    pa->PrintNameA();
    pb->PrintNameB();

    return 0;
}