#include <iostream>

namespace design_pattern::factory_method
{
#ifndef DESIGN_PATTERN_CPP_FACTORY_METHOD_H
#define DESIGN_PATTERN_CPP_FACTORY_METHOD_H

    class Product
    {
    public:
        virtual ~Product() = default;

        virtual void PrintValue() = 0;

    protected:
        int _value = 0;
    };

    class ConcreteProduct : public Product
    {
    public:
        ConcreteProduct()
        { _value = 42; }

        ~ConcreteProduct() override = default;

        void PrintValue()
        {
            std::cout << _value << std::endl;
        }
    };

    class Creator
    {
    public:
        virtual Product* FactoryMethod() = 0;
    };

    class ConcreteCreator : public Creator
    {
    public:
        ConcreteCreator()
        {
            _product = new ConcreteProduct;
        }

        ConcreteProduct* FactoryMethod() override
        {
            return _product;
        }

    private:
        ConcreteProduct* _product;
    };

#endif
}