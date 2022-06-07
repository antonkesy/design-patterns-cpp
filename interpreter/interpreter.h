#ifndef DESIGN_PATTERN_CPP_INTERPRETER_H
#define DESIGN_PATTERN_CPP_INTERPRETER_H

#include <iostream>
#include <map>
#include <string>
#include <utility>

namespace design_pattern::interpreter {

    template<class T>
    class Context {
    public:
        void Set(const std::string &var, T value) {
            _vars.insert(std::pair<std::string, T>(var, value));
        }

        T Get(const std::string &expression) {
            return _vars[expression];
        }

    private:
        std::map<const std::string, T> _vars;
    };

    template<class T>
    class AbstractExpression {
    public:
        virtual ~AbstractExpression() = default;

        virtual bool Interpret(Context<T> &context) = 0;
    };

    template<class T>
    class TerminalExpression : public AbstractExpression<T> {
    public:
        explicit TerminalExpression(std::string val) : _value(std::move(val)) {}

        ~TerminalExpression() override = default;

        T Interpret(Context<T> &context) override {
            return context.Get(_value);
        }

    private:
        const std::string _value;
    };

    //for example AND of left/right expression
    template<class T>
    class NonTerminalExpression : public AbstractExpression<T> {
    public:
        explicit NonTerminalExpression(AbstractExpression<T> &left, AbstractExpression<T> &right) : _left(left),
                                                                                                    _right(right) {}

        ~NonTerminalExpression() override = default;

        bool Interpret(Context<T> &context) override {
            return _left.Interpret(context) && _right.Interpret(context);
        }

    private:
        AbstractExpression<T> &_left;
        AbstractExpression<T> &_right;
    };

#endif
}