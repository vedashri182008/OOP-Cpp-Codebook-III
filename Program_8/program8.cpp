#include <iostream>

class Base {
public:
    void display() const {
        std::cout << "Base display function\n";
    }
};

class Derived : public Base {
public:
    void display() const {
        std::cout << "Derived display function\n";
    }
};

int main() {
    Derived derivedObject;
    Base* basePointer = &derivedObject;

    std::cout << "Using basePointer->display(): ";
    basePointer->display();

    std::cout << "Using derivedObject.display(): ";
    derivedObject.display();

    return 0;
}
