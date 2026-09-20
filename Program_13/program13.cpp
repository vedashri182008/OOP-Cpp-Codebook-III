#include <iostream>

class Base {
public:
    virtual ~Base() {
        std::cout << "Base destructor executed\n";
    }
};

class Derived : public Base {
public:
    ~Derived() override {
        std::cout << "Derived destructor executed\n";
    }
};

int main() {
    Base* pointer = new Derived();

    std::cout << "Deleting object through Base pointer:\n";
    delete pointer;

    return 0;
}
