#include <iostream>
#include "../decorator.h"
#include "example_decorator.h"

namespace design_pattern::decorator_design_pattern
{

    int example_usage_food()
    {
        FoodComponent* burger = new Burger();

        //dynamically add decorator to burger
        burger = new Salad(burger);
        burger = new Meat(burger);
        burger = new Salad(burger);

        //call operation for all children (for example get price)
        std::cout << burger->getPrice() << std::endl;

        delete burger;

        return 0;
    }

    int example_usage_generic()
    {
        Component* baseComponent = new ConcreteComponent("base");

        baseComponent = new Decorator(baseComponent);
        baseComponent = new Decorator(baseComponent);
        baseComponent = new Decorator(baseComponent);

        baseComponent->Operation();

        delete baseComponent;
        return 0;
    }

}

int main()
{
    return design_pattern::decorator_design_pattern::example_usage_food() +
           design_pattern::decorator_design_pattern::example_usage_generic();
}


