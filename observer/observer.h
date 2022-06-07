#ifndef DESIGN_PATTERN_CPP_OBSERVER_H
#define DESIGN_PATTERN_CPP_OBSERVER_H

#include <iostream>
#include <list>
#include <memory>

namespace design_pattern::observer {

    class Observer {
    public:
        virtual ~Observer() = default;

        virtual void Update() = 0;
    };

    class Subject {
    public:
        void Attach(const std::shared_ptr<Observer> &observer_to_add) {
            observer_.push_back(observer_to_add);
        }

        void Detach(const std::shared_ptr<Observer> &observer_to_detach) {
            observer_.remove(observer_to_detach);
        }

        void Notify() {
            for (const auto &item: observer_) {
                item->Update();
            }
        }

    private:
        std::list<std::shared_ptr<Observer >> observer_;
    };

    class ConcreteObserver : public Observer {
    public:
        explicit ConcreteObserver(int id) : id_(id) {}

        ~ConcreteObserver() = default;

        void Update() override {
            std::cout << "update observer id = " << id_ << "\n";
        }

    private:
        int id_;
    };

}
#endif