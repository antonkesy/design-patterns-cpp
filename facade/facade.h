#ifndef DESIGN_PATTERN_CPP_FACADE_H
#define DESIGN_PATTERN_CPP_FACADE_H

#include <iostream>
#include <string>
#include <memory>

namespace design_pattern::facade {

    class ComponentA {
    public:
        void OperationA() {
            std::cout << _name << "\n";
        }

    private:
        std::string _name = "Component A";
    };

    class ComponentB {
    public:
        void OperationB() {
            std::cout << _name << std::endl;
        }

    private:
        std::string _name = "Component B";
    };

    class Facade {
    public:
        Facade() {
            componentA_ = std::make_unique<ComponentA>();
            componentB_ = std::make_unique<ComponentB>();
        }

        ~Facade() = default;

        void Operation() {
            componentA_->OperationA();
            componentB_->OperationB();
        }

    private:
        std::unique_ptr<ComponentA> componentA_;
        std::unique_ptr<ComponentB> componentB_;
    };

}
#endif