#include <list>
#include <iostream>
#include "../iterator.h"

#define TEST_LIST_SIZE 5

namespace design_pattern::iterator
{

    template<class T>
    void populate_aggregate(ConcreteAggregate<T>& aggregate)
    {
        for (int i = 0; i < TEST_LIST_SIZE; ++i)
        {
            aggregate[i] = i;
        }
    }

    int example_usage()
    {
        ConcreteAggregate<int> list(TEST_LIST_SIZE);
        populate_aggregate(list);

        Iterator<int>* it = list.CreateIterator();
        for (it->First(); !it->IsDone(); it->Next())
        {
            std::cout << it->CurrentItem() << std::endl;
        }

        delete it;
        return 0;
    }

    int example_usage_std()
    {
        std::list<int> list;
        //populate list
        for (int i = 0; i < 10; ++i)
        {
            list.push_back(i);
        }

        //for ease of understanding simple std example (no auto)
        std::list<int>::iterator iterator = list.begin();
        while (iterator++ != list.end())
        {
            std::cout << *iterator << std::endl;
        }


        return 0;
    }

}

int main()
{
    design_pattern::iterator::example_usage_std();
    return design_pattern::iterator::example_usage();
}


