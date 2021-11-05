#include "../interpreter.h"

namespace design_pattern::interpreter
{

    int example_usage()
    {
        AbstractExpression<bool>* a = new TerminalExpression<bool>("A");
        AbstractExpression<bool>* b = new TerminalExpression<bool>("B");

        //NonTerminal is AND here
        AbstractExpression<bool>* expression = new NonTerminalExpression<bool>(a, b);

        Context<bool> context;
        context.Set("A", true);
        context.Set("B", false);

        std::cout << context.Get("A") << "&&" << context.Get("B") << '=' << expression->Interpret(context)
                  << std::endl;

        return 0;
    }

}

int main()
{
    return design_pattern::interpreter::example_usage();
}


