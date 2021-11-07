#include "../strategy.h"

namespace design_pattern::strategy
{
    int example_usage()
    {
        Context context;
        context.SetStrategy(new ConcreteStrategyA);

        context.UseStrategy();

        context.SetStrategy(new ConcreteStrategyB);
        context.UseStrategy();
        return 0;
    }

}

int main()
{
    return design_pattern::strategy::example_usage();
}


