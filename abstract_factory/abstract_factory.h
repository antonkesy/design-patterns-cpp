#ifndef DESIGN_PATTERN_CPP_ABSTRACT_FACTORY_H
#define DESIGN_PATTERN_CPP_ABSTRACT_FACTORY_H

#include <string>
#include <utility>
#include <iostream>
#include <memory>

namespace design_pattern::abstract_factory {

    class AbstractProductA {
    public:
        virtual ~AbstractProductA() = default;

        virtual void PrintNameA() = 0;
    };

    class ProductA1 : public AbstractProductA {
    public:
        ~ProductA1() override = default;

        void PrintNameA() override {
            std::cout << "A1\n";
        }
    };

    class ProductA2 : public AbstractProductA {
    public:
        ~ProductA2() override = default;

        void PrintNameA() override {
            std::cout << "A2\n";
        }
    };

    class AbstractProductB {
    public:
        virtual ~AbstractProductB() = default;

        virtual void PrintNameB() = 0;
    };

    class ProductB1 : public AbstractProductB {
    public:
        ~ProductB1() override = default;

        void PrintNameB() override {
            std::cout << "B1\n";
        }
    };

    class ProductB2 : public AbstractProductB {
    public:
        ~ProductB2() override = default;

        void PrintNameB() override {
            std::cout << "B2\n";
        }
    };


    class AbstractFactory {
    public:
        virtual ~AbstractFactory() = default;

        virtual std::unique_ptr<AbstractProductA> CreateProductA() = 0;

        virtual std::unique_ptr<AbstractProductB> CreateProductB() = 0;
    };

    class ConcreteFactory1 : public AbstractFactory {
    public:
        std::unique_ptr<AbstractProductA> CreateProductA() override {
            return std::make_unique<ProductA1>();
        }

        std::unique_ptr<AbstractProductB> CreateProductB() override {
            return std::make_unique<ProductB1>();
        }
    };


    class ConcreteFactory2 : public AbstractFactory {
    public:
        std::unique_ptr<AbstractProductA> CreateProductA() override {
            return std::make_unique<ProductA2>();
        }

        std::unique_ptr<AbstractProductB> CreateProductB() override {
            return std::make_unique<ProductB2>();
        }
    };


    class Client {
    public:
        explicit Client(bool isType1) {
            if (isType1)
                abstractFactory_ = std::make_unique<ConcreteFactory1>();
            else
                abstractFactory_ = std::make_unique<ConcreteFactory2>();
        }

        std::unique_ptr<AbstractProductA> CreateProductA() {
            return abstractFactory_->CreateProductA();
        }

        std::unique_ptr<AbstractProductB> CreateProductB() {
            return abstractFactory_->CreateProductB();
        }

    private:
        std::unique_ptr<AbstractFactory> abstractFactory_;
    };

}
#endif
