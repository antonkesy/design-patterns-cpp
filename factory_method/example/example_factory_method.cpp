#include "../factory_method.h"

namespace design_pattern::factory_method
{

    int example_usage()
    {
        ConcreteCreator creator;
        Product* p = creator.FactoryMethod();
        p->PrintValue();

        return 0;
    }

}

int main()
{
    return design_pattern::factory_method::example_usage();
}


