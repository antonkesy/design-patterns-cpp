#include "../singleton.h"

namespace design_pattern::singleton_design_pattern {

    int example_usage()
    {
        design_pattern::singleton_design_pattern::Singleton& s1 = Singleton::getSingleton();
        Singleton& s2 = Singleton::getSingleton();
        if (&s1 != &s2)
        {
            return 1;
        }
        return 0;
    }

}

int main()
{
    return design_pattern::singleton_design_pattern::example_usage();
}

