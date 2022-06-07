#include "../strategy.h"

int main() {
    using design_pattern::strategy::Context;
    using design_pattern::strategy::ConcreteStrategyA;
    using design_pattern::strategy::ConcreteStrategyB;

    Context context;
    context.SetStrategy(std::make_unique<ConcreteStrategyA>());

    context.UseStrategy();

    context.SetStrategy(std::make_unique<ConcreteStrategyB>());
    context.UseStrategy();

    return 0;
}