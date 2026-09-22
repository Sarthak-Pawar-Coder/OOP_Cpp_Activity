#include <iostream>
using namespace std;

// Define a class named Test
class Test {
private:
    int value; // Private data member

public:
    // Parameterized constructor
    Test(int v) {
        value = v;
    }

    // Inline function to return private value
    inline int getValue() {
        return value;
    }

    // Declare show() as a friend function
    friend void show(Test t);
};

// Friend function definition
void show(Test t) {
    // Friend function can access private data
    cout << t.value;
}

int main() {
    // Create object and pass 50 to constructor
    Test obj(50);

    // Call inline member function
    cout << obj.getValue() << endl;

    // Call friend function
    show(obj);

    return 0; // End of program
}