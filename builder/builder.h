#include <string>
#include <utility>
#include <iostream>

namespace design_pattern::builder
{
#ifndef DESIGN_PATTERN_CPP_BUILDER_H
#define DESIGN_PATTERN_CPP_BUILDER_H

    //placeholder class with possible different attribute values to showcase Builder
    class ObjectToBuild
    {
    public:
        ObjectToBuild() = default;

        ~ObjectToBuild() = default;

        void SetValue(int value)
        {
            _value = value;
        }

        void PrintInfo()
        {
            std::cout << _name << " " << _value << std::endl;
        }

        void SetName(const char* string)
        {
            _name = string;
        }

        /*
         * ...
         */

    private:
        std::string _name;
        int _value = 0;

        /*
         * ...
         */
    };

    class Builder
    {
    public:
        virtual ~Builder() = 0;

        virtual void BuildPartA() = 0;

        virtual void BuildPartB() = 0;

        /*
         * ...
         */

        ObjectToBuild* GetResult()
        {
            return _objToBuild;
        };

    protected:
        ObjectToBuild* _objToBuild = nullptr;
    };

    class ConcreteBuilderX : public Builder
    {
    public:
        ConcreteBuilderX()
        {
            _objToBuild = new ObjectToBuild;
        }

        ~ConcreteBuilderX() override
        {
            delete _objToBuild;
        }

        void BuildPartA() override
        {
            _objToBuild->SetName("X-A");
        }

        void BuildPartB() override
        {
            _objToBuild->SetValue(42);
        }

        /*
         * ...
         */
    };

    class ConcreteBuilderY : public Builder
    {
    public:
        ConcreteBuilderY()
        {
            _objToBuild = new ObjectToBuild;
        }

        ~ConcreteBuilderY() override
        {
            delete _objToBuild;
        }

        void BuildPartA() override
        {
            _objToBuild->SetName("Y-A");
        }

        void BuildPartB() override
        {
            _objToBuild->SetValue(73);
        }

        /*
         * ...
         */
    };

    class Director
    {
    public:
        explicit Director(Builder* builder) : _builder(builder)
        {}

        virtual ~Director()
        {
            delete _builder;
        }

        void Construct()
        {
            if (_builder == nullptr)
            {
                return;
            }
            _builder->BuildPartA();
            _builder->BuildPartB();

            /*
             * ...
             */

            _builder->GetResult()->PrintInfo();
        }

        void SetBuilder(Builder* builder)
        {
            if (_builder != nullptr)
            {
                delete _builder;
            }
            _builder = builder;
        }

    private:
        Builder* _builder = nullptr;
    };

#endif
}