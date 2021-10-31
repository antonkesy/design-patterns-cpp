#include "../abstract_factory.h"

namespace design_pattern::abstract_factory
{

    int example_usage()
    {
        Client c(true);

        AbstractProductA* pa = c.CreateProductA();
        AbstractProductB* pb = c.CreateProductB();

        pa->PrintNameA();
        pb->PrintNameB();

        delete pa;
        delete pb;

        return 0;
    }

}

int main()
{
    return design_pattern::abstract_factory::example_usage();
}


