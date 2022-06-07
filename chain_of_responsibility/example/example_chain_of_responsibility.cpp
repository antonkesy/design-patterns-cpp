#include "../chain_of_responsibility.h"

int main() {
    using design_pattern::chain_of_responsibility::ConcreteHandler;
    using design_pattern::chain_of_responsibility::TypeOfProblem;

    ConcreteHandler handlerBottom(nullptr, TypeOfProblem::TYP1, "Handler Bottom TYP 1");
    ConcreteHandler handlerTop(std::make_shared<ConcreteHandler>(handlerBottom), TypeOfProblem::TYP2,
                               "Handler Top TYP2");

    TypeOfProblem typ1 = TypeOfProblem::TYP1;
    TypeOfProblem typ2 = TypeOfProblem::TYP2;
    handlerTop.HandleRequest(typ1);
    handlerTop.HandleRequest(typ2);

    return 0;
}


