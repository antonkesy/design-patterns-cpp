#include "../flyweight.h"

namespace design_pattern::flyweight
{

    int example_usage()
    {
        FlyweightFactory factory;
        factory.GetFlyweight(1)->Operation();
        factory.GetFlyweight(1)->Operation();
        factory.GetFlyweight(2)->Operation();

        return 0;
    }

}

int main()
{
    return design_pattern::flyweight::example_usage();
}

