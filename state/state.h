#include <iostream>
#include <list>

namespace design_pattern::state
{
#ifndef DESIGN_PATTERN_CPP_STATE_H
#define DESIGN_PATTERN_CPP_STATE_H

    class State
    {
    public:
        virtual ~State() = default;

        virtual void Handle() = 0;
    };

    class ConcreteState1 : public State
    {
    public:
        ~ConcreteState1() override = default;

        void Handle() override
        {
            std::cout << "concrete state 1" << std::endl;
        }
    };

    class ConcreteState2 : public State
    {
    public:
        ~ConcreteState2() override = default;

        void Handle() override
        {
            std::cout << "concrete state 2" << std::endl;
        }
    };

    class Context
    {
    public:
        explicit Context() = default;

        ~Context()
        {
            delete _state;
        }

        void Request()
        {
            if (_state)
                _state->Handle();
        }

        void SetState(State* state)
        {
            delete _state;
            _state = state;
        }

    private:
        State* _state = nullptr;
    };

#endif
}