#include "../flyweight.h"

int main() {
    using design_pattern::flyweight::FlyweightFactory;

    FlyweightFactory factory;
    factory.GetFlyweight(1)->Operation();
    factory.GetFlyweight(1)->Operation();
    factory.GetFlyweight(2)->Operation();

    return 0;
}