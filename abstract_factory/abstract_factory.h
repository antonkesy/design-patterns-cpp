#include <string>
#include <utility>
#include <iostream>

namespace design_pattern::abstract_factory_design_pattern
{
#ifndef DESIGN_PATTERN_CPP_ABSTRACT_FACTORY_H
#define DESIGN_PATTERN_CPP_ABSTRACT_FACTORY_H

    class AbstractProductA
    {
    public:
        virtual ~AbstractProductA() = default;

        virtual void PrintNameA() = 0;
    };

    class ProductA1 : public AbstractProductA
    {
    public:
        ~ProductA1() override = default;

        void PrintNameA() override
        {
            std::cout << "A1" << std::endl;
        }
    };

    class ProductA2 : public AbstractProductA
    {
    public:
        ~ProductA2() override = default;

        void PrintNameA() override
        {
            std::cout << "A2" << std::endl;
        }
    };

    class AbstractProductB
    {
    public:
        virtual ~AbstractProductB() = default;

        virtual void PrintNameB() = 0;
    };

    class ProductB1 : public AbstractProductB
    {
    public:
        ~ProductB1() = default;

        void PrintNameB() override
        {
            std::cout << "B1" << std::endl;
        }
    };

    class ProductB2 : public AbstractProductB
    {
    public:
        ~ProductB2() = default;

        void PrintNameB() override
        {
            std::cout << "B2" << std::endl;
        }
    };


    class AbstractFactory
    {
    public:
        virtual ~AbstractFactory() = default;

        virtual AbstractProductA* CreateProductA() = 0;

        virtual AbstractProductB* CreateProductB() = 0;
    };

    class ConcreteFactory1 : public AbstractFactory
    {
    public:
        AbstractProductA* CreateProductA() override
        {
            return new ProductA1;
        }

        AbstractProductB* CreateProductB() override
        {
            return new ProductB1;
        }
    };


    class ConcreteFactory2 : public AbstractFactory
    {
    public:
        AbstractProductA* CreateProductA() override
        {
            return new ProductA2;
        }

        AbstractProductB* CreateProductB() override
        {
            return new ProductB2;
        }
    };


    class Client
    {
    public:
        explicit Client(bool isType1)
        {
            if (isType1)
                _abstractFactory = new ConcreteFactory1;
            else
                _abstractFactory = new ConcreteFactory2;
        }

        ~Client()
        {
            delete _abstractFactory;
        }

        AbstractProductA* CreateProductA()
        {
            return _abstractFactory->CreateProductA();
        }

        AbstractProductB* CreateProductB()
        {
            return _abstractFactory->CreateProductB();
        }

    private:
        AbstractFactory* _abstractFactory;
    };

#endif
}