#include <string>
#include <iostream>

namespace design_pattern::adapter
{
#ifndef DESIGN_PATTERN_CPP_ADAPTER_H
#define DESIGN_PATTERN_CPP_ADAPTER_H

    //interface which gets called by client
    class Target
    {
    public:
        virtual ~Target() = default;

        virtual void Request() = 0;
    };

    //Class with other implementation which can be only accessed through the adapter
    class Adaptee
    {
    public:
        void SpecificRequest()
        {
            std::cout << "specific request" << std::endl;
        }
    };

    //Adapter which allows the client to use Adaptee functions
    class Adapter : public Target
    {
    public:
        Adapter()
        {
            _adaptee = new Adaptee;
        }

        ~Adapter() override
        {
            delete _adaptee;
        }

        void Request() override
        {
            _adaptee->SpecificRequest();
        }

    private:
        Adaptee* _adaptee = nullptr;
    };

#endif
}