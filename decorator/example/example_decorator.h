#ifndef DESIGN_PATTERN_CPP_EXAMPLE_DECORATOR_H
#define DESIGN_PATTERN_CPP_EXAMPLE_DECORATOR_H

namespace design_pattern::decorator_design_pattern
{
    class FoodComponent
    {
    public:
        virtual ~FoodComponent() = default;

        virtual int getPrice()
        {
            return _price;
        }

    private:
        int _price = 0;
    };

    class FoodDecorator : public FoodComponent
    {
    public:
        explicit FoodDecorator(FoodComponent* component) : _component(component)
        {}

        ~FoodDecorator() override
        {
            delete _component;
        }

        int getPrice() override
        {
            return _price + _component->getPrice();
        }

    protected:
        FoodComponent* _component;
    private:
        int _price = 0;
    };

    class Burger : public FoodComponent
    {
    public:
        ~Burger() override = default;

        int getPrice() override
        {
            return _price;
        }

    private:
        int _price = 300;
    };

    class Salad : public FoodDecorator
    {
    public:
        explicit Salad(FoodComponent* component) : FoodDecorator(component)
        {}

        int getPrice() override
        {
            return _price + _component->getPrice();
        }

    protected:
        int _price = 20;
    };

    class Meat : public FoodDecorator
    {
    public:
        explicit Meat(FoodComponent* component) : FoodDecorator(component)
        {}

        int getPrice() override
        {
            return _price + _component->getPrice();
        }

    protected:
        int _price = 200;
    };
}

#endif //DESIGN_PATTERN_CPP_EXAMPLE_DECORATOR_H

