#include "../null_object.h"

namespace design_pattern::null_object
{
    int example_usage()
    {
        RealOperation po;
        po.Request();

        NullOperation no;
        no.Request();
        return 0;
    }

}

int main()
{
    return design_pattern::null_object::example_usage();
}


