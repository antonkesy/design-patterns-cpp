#include "../builder.h"

namespace design_pattern::builder
{

    int example_usage()
    {
        Director director(new ConcreteBuilderX);
        director.Construct();
        director.SetBuilder(new ConcreteBuilderY);
        director.Construct();

        return 0;
    }

}

int main()
{
    return design_pattern::builder::example_usage();
}


