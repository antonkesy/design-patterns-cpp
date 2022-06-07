#include "../visitor.h"

int main() {
    using design_pattern::visitor::ConcreteVisitor1;
    using design_pattern::visitor::ConcreteVisitor2;
    using design_pattern::visitor::ConcreteElementA;
    using design_pattern::visitor::ConcreteElementB;

    ConcreteElementA elementA;
    ConcreteElementB elementB;

    ConcreteVisitor1 visitor1;
    ConcreteVisitor2 visitor2;

    elementA.Accept(visitor1);
    elementA.Accept(visitor2);

    elementB.Accept(visitor1);
    elementB.Accept(visitor2);

    return 0;
}