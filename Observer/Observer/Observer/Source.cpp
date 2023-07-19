#include <iostream>
#include <vector>

// Observer interface
class Observer {
public:
    virtual void update(const std::string& message) = 0;
};

// Subject class
class Subject {
private:
    std::vector<Observer*> observers;
    std::string message;

public:
    void attach(Observer* observer) {
        observers.push_back(observer);
    }

    void detach(Observer* observer) {
        // Remove the observer from the list
        auto it = std::find(observers.begin(), observers.end(), observer);
        if (it != observers.end()) {
            observers.erase(it);
        }
    }

    void notify() {
        for (Observer* observer : observers) {
            observer->update(message);
        }
    }

    void setMessage(const std::string& newMessage) {
        message = newMessage;
        notify();
    }
};

// Concrete Observer classes
class ConcreteObserver : public Observer {
public:
    void update(const std::string& message) override {
        std::cout << "Received message: " << message << std::endl;
    }
};

int main() {
    // Create the subject and observers
    Subject subject;
    ConcreteObserver observer1;
    ConcreteObserver observer2;

    // Attach the observers to the subject
    subject.attach(&observer1);
    subject.attach(&observer2);

    // Set a new message in the subject
    subject.setMessage("Hello, Observers!");

    // Detach one observer and set a new message
    subject.detach(&observer2);
    subject.setMessage("Observer2 detached.");

    return 0;
}