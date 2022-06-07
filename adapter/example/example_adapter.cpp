#include "../adapter.h"

int main() {
    using design_pattern::adapter::Adapter;

    Adapter target;
    target.Request();

    return 0;
}