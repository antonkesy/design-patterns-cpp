#include <iostream>

namespace design_pattern::proxy
{
#ifndef DESIGN_PATTERN_CPP_PROXY_H
#define DESIGN_PATTERN_CPP_PROXY_H

    //interface what proxy has to forward to real subject
    class Subject
    {
    public:
        virtual ~Subject() = default;

        virtual void Request() = 0;
    };

    class RealSubject : public Subject
    {
    public:
        RealSubject()
        {
            std::cout << "RealSubject constructor" << std::endl;
        }

        ~RealSubject() override = default;

        void Request() override
        {
            std::cout << "real subject request" << std::endl;
        }
    };

    //manages real subject and access to it
    class Proxy : public Subject
    {
    public:
        ~Proxy() override
        {
            delete _real_subject;
        }

        void Request() override
        {
            GetRealSubject()->Request();
        }

        //could overload operators for easier access to subject object
        RealSubject* operator->()
        {
            return GetRealSubject();
        }

        RealSubject operator*()
        {
            return *GetRealSubject();
        }

    private:
        RealSubject* GetRealSubject()
        {
            if (_real_subject == nullptr)
            {
                _real_subject = new RealSubject;
            }
            return _real_subject;
        }

        RealSubject* _real_subject = nullptr;
    };

#endif
}