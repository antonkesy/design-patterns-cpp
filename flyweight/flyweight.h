#ifndef DESIGN_PATTERN_CPP_FLYWEIGHT_H
#define DESIGN_PATTERN_CPP_FLYWEIGHT_H

#include <map>
#include <iostream>
#include <memory>

namespace design_pattern::flyweight {

    class Flyweight {
    public:
        virtual ~Flyweight() = default;

        virtual void Operation() = 0;
    };

    //implements Flyweight interface and adds storage for intrinsic state
    class ConcreteFlyweight : public Flyweight {
    public:
        explicit ConcreteFlyweight(int intrinsic_state) : intrinsic_state_(intrinsic_state) {
            std::cout << "Create ConcreteFlyweight with state " << intrinsic_state_ << "\n";
        }

        ~ConcreteFlyweight() override = default;

        void Operation() override {
            std::cout << "ConcreteFlyweight with state " << intrinsic_state_ << "\n";
        }

    private:
        int intrinsic_state_;
    };

    //not all subclasses need to be shared
    class UnsharedConcreteFlyweight : public Flyweight {
    public:
        explicit UnsharedConcreteFlyweight(int state) : state_(state) {}

        ~UnsharedConcreteFlyweight() override = default;

        void Operation() override {
            std::cout << "Unshared Flyweight with state " << state_ << "\n";
        }

    private:
        int state_;
    };

    //creates and manages flyweights
    class FlyweightFactory {
    public:
        ~FlyweightFactory() = default;

        std::shared_ptr<Flyweight> GetFlyweight(int key) {
            //check if flyweight is already in pool;
            if (_flyweights.find(key) != _flyweights.end()) {
                return _flyweights[key];
            }
            //create new flyweight if not in pool already
            auto new_flyweight = std::make_shared<ConcreteFlyweight>(key);
            _flyweights.insert(std::pair<int, std::shared_ptr<Flyweight> >(key, new_flyweight));
            return new_flyweight;
        }

    private:
        std::map<int, std::shared_ptr<Flyweight> > _flyweights;
    };

}
#endif