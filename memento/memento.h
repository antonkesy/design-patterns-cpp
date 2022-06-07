#ifndef DESIGN_PATTERN_CPP_MEMENTO_H
#define DESIGN_PATTERN_CPP_MEMENTO_H

#include <string>
#include <utility>
#include <list>
#include <iostream>
#include <memory>

namespace design_pattern::memento {

    //just a placeholder for simplicity
    class State {
    public:
        State() = default;

        explicit State(std::string value) : value(std::move(value)) {}

        State &operator=(const State &other) = default;

        std::string value;
        //...
    };

    /*
     * stores and encapsulates the Originator object state
     */
    class Memento {
    public:
        virtual ~Memento() = default;

    private:
        //Memento should only be accessible from Originator
        friend class Originator;

        explicit Memento(State &state) : state_(state) {}

        State &GetState() {
            return state_;
        }

        //here redundant because state is always set in constructor
        void SetState(const State &state) {
            state_ = state;
        }

    private:
        State &state_;
    };

    /*
     * creates memento snapshotting current internal states for restoring the internal state later
     */
    class Originator {
    public:
        void SetMemento(Memento &memento) {
            state_ = std::make_shared<State>(memento.GetState());
        }

        std::unique_ptr<Memento> CreateMemento() {
            return std::unique_ptr<Memento>(new Memento(*state_));
        }

        //ONLY FOR EXAMPLE PURPOSE
        void SetState(std::shared_ptr<State> state) {
            state_ = std::move(state);
        }

        //ONLY FOR EXAMPLE PURPOSE
        std::shared_ptr<State> &GetState() {
            return state_;
        }

    private:
        std::shared_ptr<State> state_;
    };

    /*
     * keeps mementos safe
     */
    class Caretaker {
    public:
        explicit Caretaker(Originator &originator) : originator_(originator) {}

        ~Caretaker() = default;

        void Save() {
            history_.push_back(originator_.CreateMemento());
        }

        void Undo() {
            if (history_.empty()) {
                std::cout << "no history\n";
            }

            auto last_memento = std::move(history_.back());
            originator_.SetMemento(*last_memento);
            history_.pop_back();
        }

    private:
        Originator &originator_;
        std::list<std::unique_ptr<Memento >> history_;
    };

#endif
}