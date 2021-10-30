#include "../bridge.h"
#include "example_bridge.h"

namespace design_pattern::bridge_design_pattern
{

    int example_usage()
    {
        Abstraction a(false);
        a.Operation();
        a.SetImplementor(new ConcreteImplementorB);
        a.Operation();

        RefinedAbstraction ra;
        ra.Operation();

        return 0;
    }

    bool is_list_holder_correct(bool isList)
    {
        ListHolder<int> lh1(isList ? 500 : 50);
        int testValues[] = {1, 2, 3, 4, 5, 6};
        for (int& testValue: testValues)
        {
            lh1.AddElement(testValue);
        }

        int deleted_value = lh1[3];
        lh1.RemoveElement(testValues[3]);

        return deleted_value != lh1[3];
    }

    int list_example_usage()
    {
        return (is_list_holder_correct(true) && is_list_holder_correct(false)) ? 0 : 1;
    }
}

int main()
{
    return design_pattern::bridge_design_pattern::example_usage() +
           design_pattern::bridge_design_pattern::list_example_usage();
}


