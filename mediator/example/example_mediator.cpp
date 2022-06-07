#include "../mediator.h"

int main() {
    using design_pattern::mediator::Colleague;
    using design_pattern::mediator::ConcreteColleague;
    using design_pattern::mediator::ConcreteMediator;

    ConcreteMediator mediator;
    ConcreteColleague c1(mediator, 1U);
    ConcreteColleague c2(mediator, 2U);
    ConcreteColleague c3(mediator, 3U);

    mediator.Add(std::make_shared<ConcreteColleague>(c1));
    mediator.Add(std::make_shared<ConcreteColleague>(c2));
    mediator.Add(std::make_shared<ConcreteColleague>(c3));

    c1.Send(42);
    c2.Send(73);

    return 0;
}