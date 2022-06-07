#ifndef DESIGN_PATTERN_CPP_PROXY_H
#define DESIGN_PATTERN_CPP_PROXY_H

#include <iostream>
#include <memory>

namespace design_pattern::proxy {

    //interface what proxy has to forward to real subject
    class Subject {
    public:
        virtual ~Subject() = default;

        virtual void Request() = 0;
    };

    class RealSubject : public Subject {
    public:
        RealSubject() {
            std::cout << "RealSubject constructor\n";
        }

        ~RealSubject() override = default;

        void Request() override {
            std::cout << "real subject request\n";
        }
    };

    //manages real subject and access to it
    class Proxy : public Subject {
    public:
        ~Proxy() override = default;

        void Request() override {
            std::cout << "request proxy\n";
            GetRealSubject()->Request();
        }

    private:
        std::unique_ptr<RealSubject> &GetRealSubject() {
            if (real_subject_ == nullptr) {
                real_subject_ = std::make_unique<RealSubject>();
            }
            return real_subject_;
        }

        std::unique_ptr<RealSubject> real_subject_ = nullptr;
    };

}
#endif