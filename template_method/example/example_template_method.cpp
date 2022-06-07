#include "../template_method.h"

int main() {
    using design_pattern::template_method::ConcreteClass;

    ConcreteClass c;
    c.TemplateMethod();

    return 0;
}