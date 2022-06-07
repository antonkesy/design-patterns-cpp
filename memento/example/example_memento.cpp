#include "../memento.h"

int main() {
    using design_pattern::memento::Originator;
    using design_pattern::memento::Caretaker;
    using design_pattern::memento::State;

    Originator originator;
    Caretaker caretaker(originator);

    originator.SetState(std::make_shared<State>("1"));
    caretaker.Save();

    originator.SetState(std::make_shared<State>("2"));
    caretaker.Save();

    originator.SetState(std::make_shared<State>("3"));
    caretaker.Undo();

    std::cout << "originator state value = " << originator.GetState()->value << "\n";

    return 0;
}