#ifndef DESIGN_PATTERN_CPP_PROTOTYPE_H
#define DESIGN_PATTERN_CPP_PROTOTYPE_H

#include <iostream>
#include <memory>

namespace design_pattern::prototype {

    class Prototype {
    public:
        virtual ~Prototype() = default;

        virtual std::unique_ptr<Prototype> Clone() = 0;

        virtual void PrintInfo() = 0;
    };

    class ConcretePrototype1 : public Prototype {
    public:
        ~ConcretePrototype1() override = default;

        std::unique_ptr<Prototype> Clone() override {
            //flat copy is enough here
            return std::make_unique<ConcretePrototype1>(*this);
        }

        void PrintInfo() override {
            std::cout << "P1\n";
        }
    };

    class ConcretePrototype2 : public Prototype {
    public:
        ~ConcretePrototype2() override = default;

        std::unique_ptr<Prototype> Clone() override {
            //flat copy is enough here
            return std::make_unique<ConcretePrototype2>(*this);
        }

        void PrintInfo() override {
            std::cout << "P2\n";
        }
    };

    class Client {
    public:
        explicit Client(Prototype &prototype) : prototype_(prototype) {}

        ~Client() = default;

        void Operation() {
            auto clone = prototype_.Clone();
            /*
             * ... do something with clone
             */
            clone->PrintInfo();
        }

    private:
        Prototype &prototype_;
    };

}
#endif