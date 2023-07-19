#include <iostream>
#include <string>
#include <vector>

// Memento
class Memento {
private:
    std::string state;

public:
    Memento(const std::string& state) : state(state) {}

    std::string getState() const {
        return state;
    }
};

// Originator
class Originator {
private:
    std::string state;

public:
    void setState(const std::string& state) {
        this->state = state;
    }

    std::string getState() const {
        return state;
    }

    Memento* createMemento() const {
        return new Memento(state);
    }

    void restoreFromMemento(const Memento* memento) {
        state = memento->getState();
    }
};

// Caretaker
class Caretaker {
private:
    std::vector<Memento*> mementos;

public:
    void addMemento(Memento* memento) {
        mementos.push_back(memento);
    }

    Memento* getMemento(int index) const {
        if (index >= 0 && index < mementos.size()) {
            return mementos[index];
        }
        return nullptr;
    }
};

int main() {
    Originator originator;
    Caretaker caretaker;

    // Set initial state
    originator.setState("State 1");
    std::cout << "Current state: " << originator.getState() << std::endl;

    // Save the state
    caretaker.addMemento(originator.createMemento());

    // Change the state
    originator.setState("State 2");
    std::cout << "Current state: " << originator.getState() << std::endl;

    // Save the state
    caretaker.addMemento(originator.createMemento());

    // Change the state again
    originator.setState("State 3");
    std::cout << "Current state: " << originator.getState() << std::endl;

    // Save the state
    caretaker.addMemento(originator.createMemento());

    // Change the state again
    originator.setState("State 4");
    std::cout << "Current state: " << originator.getState() << std::endl;

    // Restore to previous state
    originator.restoreFromMemento(caretaker.getMemento(2));
    std::cout << "Current state after restore: " << originator.getState() << std::endl;

    return 0;
}