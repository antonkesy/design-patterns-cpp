#include "../state.h"

namespace design_pattern::state
{
    int example_usage()
    {
        Context context;

        context.SetState(new ConcreteState1);
        context.Request();

        context.SetState(new ConcreteState2);
        context.Request();

        return 0;
    }

}

int main()
{
    return design_pattern::state::example_usage();
}


