#include <iostream>

namespace design_pattern::strategy
{
#ifndef DESIGN_PATTERN_CPP_STRATEGY_H
#define DESIGN_PATTERN_CPP_STRATEGY_H

    class Strategy
    {
    public:
        virtual ~Strategy() = default;

        virtual void AlgorithmInterface() = 0;
    };

    class ConcreteStrategyA : public Strategy
    {
    public:
        ~ConcreteStrategyA() override = default;

        void AlgorithmInterface() override
        {
            std::cout << "Strategy A" << std::endl;
        }
    };

    class ConcreteStrategyB : public Strategy
    {
    public:
        ~ConcreteStrategyB() override = default;

        void AlgorithmInterface() override
        {
            std::cout << "Strategy B" << std::endl;
        }
    };

    class Context
    {
    public:
        ~Context()
        {
            delete _strategy;
        }

        void UseStrategy()
        {
            if (_strategy)
                _strategy->AlgorithmInterface();
        }

        void SetStrategy(Strategy* strategy)
        {
            delete _strategy;
            _strategy = strategy;
        }

    private:
        Strategy* _strategy = nullptr;
    };

#endif
}