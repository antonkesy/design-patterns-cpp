#include "../prototype.h"

namespace design_pattern::prototype
{

    int example_usage()
    {
        Client c(new ConcretePrototype1);
        c.Operation();

        Client c2(new ConcretePrototype2);
        c2.Operation();
        return 0;
    }

}

int main()
{
    return design_pattern::prototype::example_usage();
}


