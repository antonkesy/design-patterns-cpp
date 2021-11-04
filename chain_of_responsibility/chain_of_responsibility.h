#include <iostream>
#include <string>

namespace design_pattern::chain_of_responsibility
{
#ifndef DESIGN_PATTERN_CPP_CHAIN_OF_RESPONSIBILITY_H
#define DESIGN_PATTERN_CPP_CHAIN_OF_RESPONSIBILITY_H

    enum TypeOfProblem
    {
        TYP1,
        TYP2
    };

    class Handler
    {
    public:
        explicit Handler(Handler* successor, TypeOfProblem type_to_handle) : _successor(successor),
                                                                             _types_to_handle(type_to_handle)
        {}

        virtual ~Handler()
        {
            delete _successor;
        }

        virtual void HandleRequest(TypeOfProblem& problem_type)
        {
            if (_types_to_handle == problem_type)
            {
                HandleRequestSelf();
            } else if (_successor)
            {
                _successor->HandleRequest(problem_type);
            }
        };

    private:
        Handler* _successor;
        TypeOfProblem _types_to_handle;

        virtual void HandleRequestSelf() = 0;

    };

    class ConcreteHandler : public Handler
    {
    public:
        explicit ConcreteHandler(Handler* successor, TypeOfProblem typeToHandle, std::string name) : Handler(successor,
                                                                                                             typeToHandle),
                                                                                                     _name(std::move(
                                                                                                             name))
        {}

        ~ConcreteHandler() override = default;

    private:
        void HandleRequestSelf() override
        {
            std::cout << _name << std::endl;
        }

        std::string _name;
    };

#endif
}