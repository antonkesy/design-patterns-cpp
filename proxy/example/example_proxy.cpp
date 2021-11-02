#include "../proxy.h"

namespace design_pattern::proxy
{

    int example_usage()
    {
        //Client object code
        Proxy p;
        p.Request();
        p->Request();
        (*p).Request();

        return 0;
    }

}

int main()
{
    return design_pattern::proxy::example_usage();
}

