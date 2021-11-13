#include "../visitor.h"

namespace design_pattern::visitor
{
    int example_usage()
    {
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

}

int main()
{
    return design_pattern::visitor::example_usage();
}


