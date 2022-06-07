#ifndef DESIGN_PATTERN_CPP_VISITOR_H
#define DESIGN_PATTERN_CPP_VISITOR_H

#include <iostream>

namespace design_pattern::visitor {

    class ConcreteElementA;

    class ConcreteElementB;

    class Element;

    class Visitor {
    public:
        virtual ~Visitor() = default;

        virtual void VisitConcreteElementA(ConcreteElementA &concreteElementA) = 0;

        virtual void VisitConcreteElementB(ConcreteElementB &concreteElementA) = 0;
    };

    class ConcreteVisitor1 : public Visitor {
    public:
        ~ConcreteVisitor1() override = default;

        void VisitConcreteElementA(ConcreteElementA &concreteElementA) override {
            std::cout << "Concrete Visitor 1 visited by Concrete Element A\n";
        }

        void VisitConcreteElementB(ConcreteElementB &concreteElementB) override {
            std::cout << "Concrete Visitor 1 visited by Concrete Element B\n";
        }
    };

    class ConcreteVisitor2 : public Visitor {
    public:
        ~ConcreteVisitor2() override = default;

        void VisitConcreteElementA(ConcreteElementA &concreteElementA) override {
            std::cout << "Concrete Visitor 2 visited by Concrete Element A\n";
        }

        void VisitConcreteElementB(ConcreteElementB &concreteElementB) override {
            std::cout << "Concrete Visitor 2 visited by Concrete Element B\n";
        }
    };

    class Element {
    public:
        virtual void Accept(Visitor &visitor) = 0;
    };

    class ConcreteElementA : public Element {
    public:
        void Accept(Visitor &visitor) override {
            visitor.VisitConcreteElementA(*this);
        }
    };

    class ConcreteElementB : public Element {
    public:
        void Accept(Visitor &visitor) override {
            visitor.VisitConcreteElementB(*this);
        }
    };

}
#endif