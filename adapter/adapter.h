#ifndef DESIGN_PATTERN_CPP_ADAPTER_H
#define DESIGN_PATTERN_CPP_ADAPTER_H

#include <string>
#include <iostream>
#include <memory>

namespace design_pattern::adapter {

    //interface which gets called by client
    class Target {
    public:
        virtual ~Target() = default;

        virtual void Request() = 0;
    };

    //Class with other implementation which can be only accessed through the adapter
    class Adaptee {
    public:
        void SpecificRequest() {
            std::cout << _value << "\n";
        }

    private:
        std::string _value = "specific request";
    };

    //Adapter which allows the client to use Adaptee functions
    class Adapter : public Target {
    public:
        Adapter() {
            adaptee_ = std::make_unique<Adaptee>();
        }

        ~Adapter() override = default;

        void Request() override {
            adaptee_->SpecificRequest();
        }

    private:
        std::unique_ptr<Adaptee> adaptee_;
    };

}
#endif