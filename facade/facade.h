#include <iostream>
#include <string>

namespace design_pattern::facade
{
#ifndef DESIGN_PATTERN_CPP_FACADE_H
#define DESIGN_PATTERN_CPP_FACADE_H

    class ComponentA
    {
    public:
        void OperationA()
        {
            std::cout << _name << std::endl;
        }

    private:
        std::string _name = "Component A";
    };

    class ComponentB
    {
    public:
        void OperationB()
        {
            std::cout << _name << std::endl;
        }

    private:
        std::string _name = "Component B";
    };

    class Facade
    {
    public:
        Facade()
        {
            _componentA = new ComponentA;
            _componentB = new ComponentB;
        }

        ~Facade()
        {
            delete _componentA;
            delete _componentB;
        }

        void Operation()
        {
            _componentA->OperationA();
            _componentB->OperationB();
        }

    private:
        ComponentA* _componentA;
        ComponentB* _componentB;
    };

#endif
}