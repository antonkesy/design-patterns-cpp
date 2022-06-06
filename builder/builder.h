#ifndef DESIGN_PATTERN_CPP_BUILDER_H
#define DESIGN_PATTERN_CPP_BUILDER_H

#include <string>
#include <utility>
#include <iostream>
#include <memory>

namespace design_pattern::builder {
    //placeholder class with possible different attribute values to showcase Builder
    class ObjectToBuild {
    public:
        ObjectToBuild() = default;

        ~ObjectToBuild() = default;

        void SetValue(int value) {
            value_ = value;
        }

        void PrintInfo() {
            std::cout << name_ << " " << value_ << "\n";
        }

        void SetName(const char *string) {
            name_ = string;
        }

        /*
         * ...
         */

    private:
        std::string name_;
        int value_ = 0;

        /*
         * ...
         */
    };

    class Builder {
    public:
        virtual ~Builder() = default;

        virtual void BuildPartA() = 0;

        virtual void BuildPartB() = 0;

        /*
         * ...
         */

        ObjectToBuild &GetResult() {
            return *objToBuild_;
        };

    protected:
        std::shared_ptr<ObjectToBuild> objToBuild_;
    };

    class ConcreteBuilderX : public Builder {
    public:
        ConcreteBuilderX() {
            objToBuild_ = std::make_unique<ObjectToBuild>();
        }

        ~ConcreteBuilderX() override = default;

        void BuildPartA() override {
            objToBuild_->SetName("X-A");
        }

        void BuildPartB() override {
            objToBuild_->SetValue(42);
        }

        /*
         * ...
         */
    };

    class ConcreteBuilderY : public Builder {
    public:
        ConcreteBuilderY() {
            objToBuild_ = std::make_unique<ObjectToBuild>();
        }

        ~ConcreteBuilderY() override = default;

        void BuildPartA() override {
            objToBuild_->SetName("Y-A");
        }

        void BuildPartB() override {
            objToBuild_->SetValue(73);
        }

        /*
         * ...
         */
    };

    class Director {
    public:
        explicit Director(Builder &builder) : builder_(builder) {}

        virtual ~Director() = default;

        void Construct() {
            builder_.BuildPartA();
            builder_.BuildPartB();

            /*
             * ...
             */

            builder_.GetResult().PrintInfo();
        }

        void SetBuilder(Builder &builder) {
            builder_ = builder;
        }

    private:
        Builder &builder_;
    };

}
#endif
