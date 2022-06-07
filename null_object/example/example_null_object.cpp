#include "../null_object.h"

int main() {
    using design_pattern::null_object::RealOperation;
    using design_pattern::null_object::NullOperation;

    RealOperation po;
    po.Request();

    NullOperation no;
    no.Request();

    return 0;
}