#include <iostream>

namespace design_pattern::bridge_design_pattern
{
#ifndef DESIGN_PATTERN_CPP_BRIDGE_H
#define DESIGN_PATTERN_CPP_BRIDGE_H

    class Implementor
    {
    public:
        virtual ~Implementor() = default;

        virtual void OperationImp() = 0;
    };

    class ConcreteImplementorA : public Implementor
    {
    public:
        void OperationImp() override
        {
            std::cout << "ConcreteImplementation A" << std::endl;
        }
    };

    class ConcreteImplementorB : public Implementor
    {
    public:
        void OperationImp() override
        {
            std::cout << "ConcreteImplementation B" << std::endl;
        }
    };

    class Abstraction
    {
    public:
        explicit Abstraction(bool isA)
        {
            //which concrete implementation is used can be decided in other places
            //for simplicity of the example the abstraction decides it by bool parameter
            if (isA)
            {
                _imp = new ConcreteImplementorA;
            } else
            {
                _imp = new ConcreteImplementorB;
            }
        }

        virtual ~Abstraction()
        {
            delete _imp;
        }

        void Operation()
        {
            _imp->OperationImp();
        }

        void SetImplementor(Implementor* imp)
        {
            delete _imp;
            _imp = imp;
        }

    protected:
        Implementor* _imp;
    };

    //the abstraction can also be inherited
    //for example if the refined does not have full access to all implementations
    class RefinedAbstraction : public Abstraction
    {
    public:
        RefinedAbstraction() : Abstraction(true)
        {}
    };

#endif
}