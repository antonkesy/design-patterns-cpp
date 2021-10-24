#include <iostream>

namespace design_pattern::decorator_design_pattern
{
#ifndef DESIGN_PATTERN_CPP_DECORATOR_H
#define DESIGN_PATTERN_CPP_DECORATOR_H

    class Component
    {
    public:
        virtual ~Component() = default;

        virtual void Operation() = 0;

    };


    class Decorator : public Component
    {
    public:

        explicit Decorator(Component* component) : _component(component)
        {}

        ~Decorator() override
        {
            delete _component;
        }

        void Operation() override
        {
            //do decorator operation
            std::cout << "decorator operation" << std::endl;

            _component->Operation();
        }

    private:
        Component* _component;
    };

    class ConcreteComponent : public Component
    {
    public:

        explicit ConcreteComponent(std::string message) : _message(std::move(message))
        {}

        ~ConcreteComponent() override = default;

        void Operation() override
        {
            std::cout << _message << std::endl;
        }

    private:
        std::string _message;
    };

#endif
}