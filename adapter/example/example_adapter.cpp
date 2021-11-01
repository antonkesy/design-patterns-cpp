#include "../adapter.h"

namespace design_pattern::adapter
{

    int example_usage()
    {
        Target* target = new Adapter;
        target->Request();

        delete target;
        return 0;
    }

}

int main()
{
    return design_pattern::adapter::example_usage();
}


