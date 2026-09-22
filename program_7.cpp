#include <iostream>
using namespace std;

// Define Student class
class Student {
public:
    // Static variable shared by all objects
    static int count;

    // Constructor
    Student() {
        count++; // Increase count whenever an object is created
    }
};

// Define and initialize static member
int Student::count = 0;

int main() {
    // Create three objects
    Student s1;
    Student s2;
    Student s3;

    // Access static member using class name
    cout << Student::count;

    return 0; // End of program
}