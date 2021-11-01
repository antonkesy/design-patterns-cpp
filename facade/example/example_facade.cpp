#include "../facade.h"

namespace design_pattern::facade
{

    int example_usage()
    {
        Facade f;
        f.Operation();

        return 0;
    }

}

int main()
{
    return design_pattern::facade::example_usage();
}


