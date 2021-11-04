#include "../chain_of_responsibility.h"

namespace design_pattern::chain_of_responsibility
{

    int example_usage()
    {

        //create chain of responsibility dynamically
        auto handlerBottom = new ConcreteHandler(NULL, TYP1, "Handler Bottom TYP 1");
        auto handlerTop = new ConcreteHandler(handlerBottom, TYP2, "Handler Top TYP2");

        TypeOfProblem typ1 = TYP1;
        TypeOfProblem typ2 = TYP2;
        handlerTop->HandleRequest(typ1);
        handlerTop->HandleRequest(typ2);

        //only need to delete top handler
        delete handlerTop;

        return 0;
    }

}

int main()
{
    return design_pattern::chain_of_responsibility::example_usage();
}


