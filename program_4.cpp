#include <iostream>
using namespace std;

// Function prototype
int add(int, int);

int main() {
    // Declare two variables
    int a = 10;
    int b = 20;

    // Call the add function and display the result
    cout << "Sum = " << add(a, b) << endl;

    return 0; // End of program
}

// Function definition
int add(int x, int y) {
    return x + y; // Return addition of two numbers
}