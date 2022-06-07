#include <list>
#include <iostream>
#include "../iterator.h"

int main() {
    using design_pattern::iterator::ConcreteAggregate;
    using design_pattern::iterator::Iterator;

    const int test_list_size = 5;
    ConcreteAggregate<int> list(test_list_size);

    for (int i = 0; i < test_list_size; ++i) {
        list[i] = i;
    }

    auto it = list.CreateIterator();
    for (it->First(); !it->IsDone(); it->Next()) {
        std::cout << it->CurrentItem() << "\n";
    }

    return 0;
}