#include <map>
#include <iostream>

namespace design_pattern::flyweight
{
#ifndef DESIGN_PATTERN_CPP_FLYWEIGHT_H
#define DESIGN_PATTERN_CPP_SINGLETON_H

    class Flyweight
    {
    public:
        virtual ~Flyweight() = default;

        virtual void Operation() = 0;
    };

    //implements Flyweight interface and adds storage for intrinsic state
    class ConcreteFlyweight : public Flyweight
    {
    public:
        explicit ConcreteFlyweight(int intrinsic_state) : _intrinsic_state(intrinsic_state)
        {
            std::cout << "Create ConcreteFlyweight with state " << _intrinsic_state << std::endl;
        }

        ~ConcreteFlyweight() override = default;

        void Operation() override
        {
            std::cout << "ConcreteFlyweight with state " << _intrinsic_state << std::endl;
        }

    private:
        int _intrinsic_state;
    };

    //not all subclasses need to be shared
    class UnsharedConcreteFlyweight : public Flyweight
    {
    public:
        explicit UnsharedConcreteFlyweight(int state) : _state(state)
        {}

        ~UnsharedConcreteFlyweight() override = default;

        void Operation() override
        {
            std::cout << "Unshared Flyweight with state " << _state << std::endl;
        }

    private:
        int _state;
    };

    //creates and manages flyweights
    class FlyweightFactory
    {
    public:
        ~FlyweightFactory()
        {
            //delete every flyweight in pool
            for (const auto& flyweight: _flyweights)
            {
                delete flyweight.second;
            }
        }

        Flyweight* GetFlyweight(int key)
        {
            //check if flyweight is already in pool;
            if (_flyweights.find(key) != _flyweights.end())
            {
                return _flyweights[key];
            }
            //create new flyweight if not in pool already
            Flyweight* new_flyweight = new ConcreteFlyweight(key);
            _flyweights.insert(std::pair<int, Flyweight*>(key, new_flyweight));
            return new_flyweight;
        }

    private:
        std::map<int, Flyweight*> _flyweights;
    };

#endif
}