#ifndef DESIGN_PATTERN_CPP_STRATEGY_H
#define DESIGN_PATTERN_CPP_STRATEGY_H

#include <iostream>
#include <memory>

namespace design_pattern::strategy {

    class Strategy {
    public:
        virtual ~Strategy() = default;

        virtual void AlgorithmInterface() = 0;
    };

    class ConcreteStrategyA : public Strategy {
    public:
        ~ConcreteStrategyA() override = default;

        void AlgorithmInterface() override {
            std::cout << "Strategy A\n";
        }
    };

    class ConcreteStrategyB : public Strategy {
    public:
        ~ConcreteStrategyB() override = default;

        void AlgorithmInterface() override {
            std::cout << "Strategy B\n";
        }
    };

    class Context {
    public:
        ~Context() = default;

        void UseStrategy() {
            if (strategy_)
                strategy_->AlgorithmInterface();
        }

        void SetStrategy(std::unique_ptr<Strategy> strategy) {
            strategy_ = std::move(strategy);
        }

    private:
        std::unique_ptr<Strategy> strategy_ = nullptr;
    };

#endif
}