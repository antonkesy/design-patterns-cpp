#include "../state.h"

int main() {
    using design_pattern::state::Context;
    using design_pattern::state::ConcreteState1;
    using design_pattern::state::ConcreteState2;

    Context context;

    context.SetState(std::make_unique<ConcreteState1>());
    context.Request();

    ConcreteState1 state2;
    context.SetState(std::make_unique<ConcreteState2>());
    context.Request();

    return 0;
}