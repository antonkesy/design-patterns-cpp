#include <iostream>

namespace design_pattern::template_method
{
#ifndef DESIGN_PATTERN_CPP_TEMPLATE_METHOD_H
#define DESIGN_PATTERN_CPP_TEMPLATE_METHOD_H

    class AbstractClass
    {
    public:
        virtual ~AbstractClass() = default;

        void TemplateMethod()
        {
            PrimitiveOperation1();
            PrimitiveOperation2();
        }

        virtual void PrimitiveOperation1() = 0;

        virtual void PrimitiveOperation2() = 0;

    };

    class ConcreteClass : public AbstractClass
    {
    public:
        ~ConcreteClass() override = default;

        void PrimitiveOperation1() override
        {
            std::cout << "concrete primitive op 1" << std::endl;
        }

        void PrimitiveOperation2() override
        {
            std::cout << "concrete primitive op 2" << std::endl;
        }
    };

#endif
}