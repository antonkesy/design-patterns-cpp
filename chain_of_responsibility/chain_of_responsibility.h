#ifndef DESIGN_PATTERN_CPP_CHAIN_OF_RESPONSIBILITY_H
#define DESIGN_PATTERN_CPP_CHAIN_OF_RESPONSIBILITY_H

#include <iostream>
#include <string>
#include <memory>
#include <utility>

namespace design_pattern::chain_of_responsibility {

    enum TypeOfProblem {
        TYP1,
        TYP2
    };

    class Handler {
    public:
        Handler(std::shared_ptr<Handler> successor, TypeOfProblem type_to_handle) : successor_(std::move(successor)),
                                                                                    types_to_handle_(type_to_handle) {}

        virtual ~Handler() = default;

        virtual void HandleRequest(TypeOfProblem &problem_type) {
            if (types_to_handle_ == problem_type)
                HandleRequestSelf();
            else if (successor_)
                successor_->HandleRequest(problem_type);
        };

    private:
        std::shared_ptr<Handler> successor_;
        TypeOfProblem types_to_handle_;

        virtual void HandleRequestSelf() = 0;

    };

    class ConcreteHandler : public Handler {
    public:
        explicit ConcreteHandler(std::shared_ptr<Handler> successor, TypeOfProblem typeToHandle, std::string name) :
                Handler(std::move(successor), typeToHandle), name_(std::move(name)) {}

        ~ConcreteHandler() override = default;

    private:
        void HandleRequestSelf() override {
            std::cout << name_ << "\n";
        }

        std::string name_;
    };

}
#endif