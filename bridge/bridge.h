#ifndef DESIGN_PATTERN_CPP_BRIDGE_H
#define DESIGN_PATTERN_CPP_BRIDGE_H

#include <iostream>
#include <memory>

namespace design_pattern::bridge {

    class Implementor {
    public:
        virtual ~Implementor() = default;

        virtual void OperationImp() = 0;
    };

    class ConcreteImplementorA : public Implementor {
    public:
        void OperationImp() override {
            std::cout << "ConcreteImplementation A\n";
        }
    };

    class ConcreteImplementorB : public Implementor {
    public:
        void OperationImp() override {
            std::cout << "ConcreteImplementation B\n";
        }
    };

    class Abstraction {
    public:
        explicit Abstraction(bool isA) {
            //which concrete implementation is used can be decided in other places
            //for simplicity of the example the abstraction decides it by bool parameter
            if (isA) {
                imp_ = std::make_unique<ConcreteImplementorA>();
            } else {
                imp_ = std::make_unique<ConcreteImplementorB>();
            }
        }

        virtual ~Abstraction() = default;

        void Operation() {
            imp_->OperationImp();
        }

        void SetImplementor(std::unique_ptr<Implementor> new_imp) {
            imp_ = std::move(new_imp);
        }

    protected:
        std::unique_ptr<Implementor> imp_;
    };

    //the abstraction can also be inherited
    //for example if the refined does not have full access to all implementations
    class RefinedAbstraction : public Abstraction {
    public:
        RefinedAbstraction() : Abstraction(true) {}
    };

}
#endif
