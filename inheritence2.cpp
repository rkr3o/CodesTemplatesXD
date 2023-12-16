#include<bits/stdc++.h>
using namespace std;

// Base class representing a college
class College {
protected:
    string collegeName;

public:
    // Setter function to set the college name
    void setCollegeName(string name) {
        collegeName = name;
    }
};

// Derived class representing a student, privately inheriting from College
class Student : private College {
public:
    string studentName;

    // Function to set both college name and student name
    void setGlobalName(string name, string _name) {
        // Access the setCollegeName function from the base class
        setCollegeName(name);
        studentName = _name;
    }

    // Display function to print college name and student name
    void display() {
        cout << collegeName << endl;
        cout << studentName << endl;
    }
};

// Further derived class representing a global student, publicly inheriting from Student
class GlobalStudent : public Student {
public:
    // Function to set both college name and student name, exposed publicly
    void setNameName(string name, string _name) {
        setGlobalName(name, _name);
    }
};

int main() {
    // Creating an instance of the GlobalStudent class
    GlobalStudent s;

    // Setting the college name and student name
    s.setNameName("CU", "rvi");

    // Uncommenting the following lines will result in compilation errors
    // s.collegeName = "IIT";  // Error: 'College::collegeName' is protected
    // s.setStudentName("Ravi");  // Error: 'setStudentName' is not a member of 'GlobalStudent'

    // Displaying the college name and student name
    s.display();

    return 0;
}
