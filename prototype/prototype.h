#include <iostream>

namespace design_pattern::prototype
{
#ifndef DESIGN_PATTERN_CPP_PROTOTYPE_H
#define DESIGN_PATTERN_CPP_PROTOTYPE_H

    class Prototype
    {
    public:
        virtual ~Prototype() = default;

        virtual Prototype* Clone() = 0;

        virtual void PrintInfo() = 0;
    };

    class ConcretePrototype1 : public Prototype
    {
    public:
        ~ConcretePrototype1() override = default;

        ConcretePrototype1* Clone() override
        {
            //flat copy is enough here
            return new ConcretePrototype1;
        }

        void PrintInfo() override
        {
            std::cout << "P1" << std::endl;
        }
    };

    class ConcretePrototype2 : public Prototype
    {
    public:
        ~ConcretePrototype2() override = default;

        ConcretePrototype2* Clone() override
        {
            //flat copy is enough here
            return new ConcretePrototype2;
        }

        void PrintInfo() override
        {
            std::cout << "P2" << std::endl;
        }
    };

    class Client
    {
    public:
        explicit Client(Prototype* prototype) : _prototype(prototype)
        {}

        ~Client()
        {
            delete _prototype;
        }

        void Operation()
        {
            Prototype* clone = _prototype->Clone();
            /*
             * ... do something with clone
             */
            clone->PrintInfo();
            delete clone;
        }

    private:
        Prototype* _prototype = nullptr;
    };

#endif
}