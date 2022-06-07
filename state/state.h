#ifndef DESIGN_PATTERN_CPP_STATE_H
#define DESIGN_PATTERN_CPP_STATE_H

#include <iostream>
#include <list>
#include <memory>

namespace design_pattern::state {

    class State {
    public:
        virtual ~State() = default;

        virtual void Handle() = 0;
    };

    class ConcreteState1 : public State {
    public:
        ~ConcreteState1() override = default;

        void Handle() override {
            std::cout << "concrete state 1\n";
        }
    };

    class ConcreteState2 : public State {
    public:
        ~ConcreteState2() override = default;

        void Handle() override {
            std::cout << "concrete state 2\n";
        }
    };

    class Context {
    public:
        explicit Context() = default;

        ~Context() = default;

        void Request() {
            if (_state)
                _state->Handle();
        }

        void SetState(std::unique_ptr<State> state) {
            _state = std::move(state);
        }

    private:
        std::unique_ptr<State> _state = nullptr;
    };

}
#endif