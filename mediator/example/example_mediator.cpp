#include "../mediator.h"

namespace design_pattern::mediator
{
    int example_usage()
    {
        ConcreteMediator mediator;
        Colleague* c1 = new ConcreteColleague(&mediator, 1U);
        Colleague* c2 = new ConcreteColleague(&mediator, 2U);
        Colleague* c3 = new ConcreteColleague(&mediator, 3U);
        mediator.Add(c1);
        mediator.Add(c2);
        mediator.Add(c3);

        c1->Send(42);
        c2->Send(73);
        return 0;
    }

}

int main()
{
    return design_pattern::mediator::example_usage();
}


