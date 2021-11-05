#include "../command.h"

namespace design_pattern::command
{

    int example_usage()
    {
        Client c;
        c.DoSomething();
        return 0;
    }

}

int main()
{
    return design_pattern::command::example_usage();
}


