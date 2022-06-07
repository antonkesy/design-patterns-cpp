#include "../interpreter.h"

int main() {
    using design_pattern::interpreter::AbstractExpression;
    using design_pattern::interpreter::TerminalExpression;
    using design_pattern::interpreter::NonTerminalExpression;
    using design_pattern::interpreter::Context;

    TerminalExpression<bool> a("A");
    TerminalExpression<bool> b("B");

    //NonTerminal is AND here
    NonTerminalExpression<bool> expression(a, b);

    Context<bool> context;
    context.Set("A", true);
    context.Set("B", false);

    std::cout << context.Get("A") << "&&" << context.Get("B") << '=' << expression.Interpret(context)
              << "\n";

    return 0;
}