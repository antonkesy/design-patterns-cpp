#include "../builder.h"

int main() {
    using design_pattern::builder::Director;
    using design_pattern::builder::ConcreteBuilderX;
    using design_pattern::builder::ConcreteBuilderY;

    ConcreteBuilderX builderX;
    Director director(builderX);
    director.Construct();

    ConcreteBuilderY builderY;
    director.SetBuilder(builderY);
    director.Construct();

    return 0;
}