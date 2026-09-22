#include <iostream>
using namespace std;

// Define a class named Demo
class Demo {
public:

    // Constructor
    Demo() {
        cout << "Constructor called" << endl;
    }

    // Destructor
    ~Demo() {
        cout << "Destructor called" << endl;
    }
};

int main() {
    // Create an object
    // Constructor is automatically called here
    Demo d;

    // Destructor is automatically called
    // when the object goes out of scope
    return 0;
}
