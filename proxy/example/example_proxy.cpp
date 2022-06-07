#include "../proxy.h"

int main() {
    using design_pattern::proxy::Proxy;

    Proxy p;
    p.Request();
    p.Request();

    return 0;
}