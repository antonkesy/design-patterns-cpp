#include "../memento.h"

namespace design_pattern::memento
{
    int example_usage()
    {
        Originator originator;
        Caretaker caretaker(&originator);

        originator.SetState(State("1"));
        caretaker.Save();

        originator.SetState(State("2"));
        caretaker.Save();

        originator.SetState(State("3"));
        caretaker.Undo();

        std::cout << "originator state value = " << originator.GetState().value << std::endl;
        return 0;
    }

}

int main()
{
    return design_pattern::memento::example_usage();
}


