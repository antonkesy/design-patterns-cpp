#include "../builder.h"

namespace design_pattern::builder_design_pattern
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
    return design_pattern::builder_design_pattern::example_usage();
}


