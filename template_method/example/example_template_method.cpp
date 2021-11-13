#include "../template_method.h"

namespace design_pattern::template_method
{
    int example_usage()
    {
        AbstractClass* templateMethode = new ConcreteClass;
        templateMethode->TemplateMethod();

        delete templateMethode;
        return 0;
    }

}

int main()
{
    return design_pattern::template_method::example_usage();
}


