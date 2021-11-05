#include <iostream>

namespace design_pattern::command
{
#ifndef DESIGN_PATTERN_CPP_COMMAND_H
#define DESIGN_PATTERN_CPP_COMMAND_H

    class Receiver
    {
    public:
        void Action() const
        {
            std::cout << "action " << std::endl;
        }
    };

    class Command
    {
    public:
        virtual ~Command() = default;

        virtual void Execute() = 0;

    protected:
        Command() = default;
    };

    class ConcreteCommand : public Command
    {
    public:
        explicit ConcreteCommand(Receiver* receiver) : _receiver(receiver)
        {}

        ~ConcreteCommand() override
        {
            delete _receiver;
        }

        void Execute() override
        {
            _receiver->Action();
        }

    private:
        Receiver* _receiver;
    };

    class Invoker
    {
    public:
        //Command could also be set with setter
        explicit Invoker(Command* command) : _command(command)
        {}

        ~Invoker()
        {
            delete _command;
        }

        void Invoke()
        {
            _command->Execute();
        }

    private:
        Command* _command;
    };

    class Client
    {
    public:
        ~Client()
        {
            delete _invoker;
        }

        explicit Client()
        {
            auto command = new ConcreteCommand(new Receiver);
            _invoker = new Invoker(command);
        }

        void DoSomething()
        {
            _invoker->Invoke();
        }

    private:
        Invoker* _invoker;
    };

#endif
}