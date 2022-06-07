#include "../singleton.h"

int main() {
    using design_pattern::singleton::Singleton;

    auto &s1 = Singleton::getSingleton();
    auto &s2 = Singleton::getSingleton();

    if (&s1 != &s2) return -1;

    return 0;
}