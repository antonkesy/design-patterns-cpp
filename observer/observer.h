#include <iostream>
#include <list>

namespace design_pattern::observer
{
#ifndef DESIGN_PATTERN_CPP_OBSERVER_H
#define DESIGN_PATTERN_CPP_OBSERVER_H

    class Observer
    {
    public:
        virtual void Update() = 0;
    };

    class Subject
    {
    public:
        void Attach(Observer* observer_to_add)
        {
            _observer.push_back(observer_to_add);
        }

        void Detach(Observer* observer_to_detach)
        {
            _observer.remove(observer_to_detach);
        }

        void Notify()
        {
            for (const auto& item: _observer)
            {
                item->Update();
            }
        }

    private:
        std::list<Observer*> _observer;
    };

    class ConcreteObserver : public Observer
    {
    public:
        explicit ConcreteObserver(int id) : _id(id)
        {}

        ~ConcreteObserver() = default;

        void Update() override
        {
            std::cout << "update observer id = " << _id << std::endl;
        }

    private:
        int _id;
    };

#endif
}