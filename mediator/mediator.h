#include <iostream>
#include <vector>

namespace design_pattern::mediator
{
#ifndef DESIGN_PATTERN_CPP_MEDIATOR_H
#define DESIGN_PATTERN_CPP_MEDIATOR_H

    class Mediator;

    class Colleague
    {
    public:
        Colleague(Mediator* mediator, std::size_t id) : mediator(mediator), id(id)
        {}

        virtual ~Colleague() = default;

        virtual void Receive(int number) = 0;

        virtual void Send(int number) = 0;

        std::size_t GetID() const
        {
            return id;
        }

    protected:
        Mediator* mediator;
        std::size_t id;
    };

    class Mediator
    {
    public:
        virtual ~Mediator() = default;

        virtual void Notify(Colleague* colleague, int number) = 0;

    };


    class ConcreteColleague : public Colleague
    {
    public:
        ConcreteColleague(Mediator* mediator, unsigned int id) : Colleague(mediator, id)
        {}

        ~ConcreteColleague() override = default;

        void Receive(int number) override
        {
            std::cout << "colleague id=" << id << " received number=" << number << std::endl;
        }

        void Send(int number) override
        {
            std::cout << "colleague id=" << id << " send number=" << number << std::endl;
            mediator->Notify(this, number);
        }
    };

    class ConcreteMediator : public Mediator
    {
    public:
        ConcreteMediator() = default;

        ~ConcreteMediator() override
        {
            for (const auto& item: _colleagues)
            {
                delete item;
            }
        }

        void Add(Colleague* colleague)
        {
            _colleagues.push_back(colleague);
        }

        void Notify(Colleague* sender, int number) override
        {
            for (const auto& item: _colleagues)
            {
                //distribute to all except to sender
                if (item->GetID() != sender->GetID())
                {
                    item->Receive(number);
                }
            }
        }


    private:
        std::vector<Colleague*> _colleagues;
    };


#endif
}