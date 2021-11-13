#include <iostream>

namespace design_pattern::null_object
{
#ifndef DESIGN_PATTERN_CPP_NULL_OBJECT_H
#define DESIGN_PATTERN_CPP_NULL_OBJECT_H

    class AbstractOperation
    {
    public:
        virtual ~AbstractOperation() = default;

        virtual void Request() = 0;
    };

    class RealOperation : public AbstractOperation
    {
    public:
        ~RealOperation() override = default;

        void Request() override
        {
            std::cout << "real operation" << std::endl;
        }
    };

    class NullOperation : public AbstractOperation
    {
    public:
        ~NullOperation() override = default;

        void Request() override
        {
            //do nothing for example
        }
    };

#endif
}