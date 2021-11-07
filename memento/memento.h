#include <string>
#include <utility>
#include <list>
#include <iostream>

namespace design_pattern::memento
{
#ifndef DESIGN_PATTERN_CPP_MEMENTO_H
#define DESIGN_PATTERN_CPP_MEMENTO_H

    //just a placeholder for simplicity
    class State
    {
    public:
        State() = default;

        explicit State(std::string value) : value(std::move(value))
        {}

        State& operator=(const State& other) = default;

        std::string value;
        //...
    };

    /*
     * stores and encapsulates the Originator object state
     */
    class Memento
    {
    public:
        virtual ~Memento() = default;

    private:
        //Memento should only be accessible from Originator
        friend class Originator;

        explicit Memento(const State& state) : _state(state)
        {}

        State GetState()
        {
            return _state;
        }

        //here redundant because state is always set in constructor
        void SetState(const State& state)
        {
            _state = state;
        }

    private:
        State _state;
    };

    /*
     * creates memento snapshotting current internal states for restoring the internal state later
     */
    class Originator
    {
    public:
        void SetMemento(Memento* memento)
        {
            _state = memento->GetState();
        }

        Memento* CreateMemento()
        {
            return new Memento(_state);
        }

        //ONLY FOR EXAMPLE PURPOSE
        void SetState(const State& state)
        {
            _state = state;
        }

        //ONLY FOR EXAMPLE PURPOSE
        State GetState()
        {
            return _state;
        }

    private:
        State _state;
    };

    /*
     * keeps mementos safe
     */
    class Caretaker
    {
    public:
        explicit Caretaker(Originator* originator) : _originator(originator)
        {}

        ~Caretaker()
        {
            for (const auto& item: _history)
            {
                delete item;
            }
        }

        void Save()
        {
            _history.push_back(_originator->CreateMemento());
        }

        void Undo()
        {
            if (_history.empty())
            {
                std::cout << "no history" << std::endl;
            }

            Memento* last_memento = _history.back();
            _originator->SetMemento(last_memento);
            _history.pop_back();
            delete last_memento;
        }

    private:
        Originator* _originator;
        std::list<Memento*> _history;
    };

#endif
}