#ifndef DESIGN_PATTERN_CPP_FACTORY_METHOD_H
#define DESIGN_PATTERN_CPP_FACTORY_METHOD_H

#include <iostream>
#include <memory>

namespace design_pattern::factory_method {

    class Product {
    public:
        virtual ~Product() = default;

        virtual void PrintValue() = 0;

    protected:
        int _value = 0;
    };

    class ConcreteProduct : public Product {
    public:
        ConcreteProduct() { _value = 42; }

        ~ConcreteProduct() override = default;

        void PrintValue() override {
            std::cout << _value << "\n";
        }
    };

    class Creator {
    public:
        virtual std::unique_ptr<Product> FactoryMethod() = 0;
    };

    class ConcreteCreator : public Creator {
    public:
        ConcreteCreator() = default;

        std::unique_ptr<Product> FactoryMethod() override {
            return std::make_unique<ConcreteProduct>();
        }

    };

#endif
}