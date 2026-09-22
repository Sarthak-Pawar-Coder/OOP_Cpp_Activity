#include <iostream>
#include <string>
using namespace std;

// Define a class named Student
class Student {
public:
    string name; // Data member for name
    int age;     // Data member for age

    // Member function to display student details
    void show() {
        cout << name << " " << age << endl;
    }
};

int main() {
    // Create an object of Student class
    Student s1;

    // Assign values to object members
    s1.name = "Amit";
    s1.age = 20;

    // Call the member function
    s1.show();

    return 0; // End of program
}
