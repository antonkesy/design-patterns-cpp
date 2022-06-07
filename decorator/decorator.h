#ifndef DESIGN_PATTERN_CPP_DECORATOR_H
#define DESIGN_PATTERN_CPP_DECORATOR_H

#include <iostream>

namespace design_pattern::decorator {

    class Component {
    public:
        virtual ~Component() = default;

        virtual void Operation() = 0;

    };


    class Decorator : public Component {
    public:

        explicit Decorator(Component &component, std::string message) : component_(component),
                                                                        message_(std::move(message)) {}

        ~Decorator() override = default;

        void Operation() override {
            //do decorator operation
            std::cout << "decorator operation: " << message_ << "\n";

            component_.Operation();
        }

    private:
        Component &component_;
        std::string message_;
    };

    class ConcreteComponent : public Component {
    public:

        explicit ConcreteComponent(std::string message) : message_(std::move(message)) {}

        ~ConcreteComponent() override = default;

        void Operation() override {
            std::cout << "concrete component operation: " << message_ << "\n";
        }

    private:
        std::string message_;
    };

#endif
}