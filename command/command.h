#ifndef DESIGN_PATTERN_CPP_COMMAND_H
#define DESIGN_PATTERN_CPP_COMMAND_H

#include <iostream>
#include <memory>

namespace design_pattern::command {

    class Receiver {
    public:
        void Action() const {
            std::cout << "action " << randomValue_ << "\n";
        }

    private:
        int randomValue_ = 42;
    };

    class Command {
    public:
        virtual ~Command() = default;

        virtual void Execute() = 0;

    };

    class ConcreteCommand : public Command {
    public:
        explicit ConcreteCommand(Receiver &receiver) : receiver_(receiver) {}

        ~ConcreteCommand() override = default;

        void Execute() override {
            receiver_.Action();
        }

    private:
        Receiver &receiver_;
    };

    class Invoker {
    public:
        explicit Invoker(Command &command) : command_(command) {}

        virtual ~Invoker() = default;

        void Invoke() {
            command_.Execute();
        }

    private:
        Command &command_;
    };

    class Client {
    public:
        explicit Client() : command_(receiver_), invoker_(command_) {
        }

        virtual ~Client() = default;

        void DoSomething() {
            invoker_.Invoke();
        }

    private:
        Receiver receiver_;
        ConcreteCommand command_;
        Invoker invoker_;
    };

}
#endif