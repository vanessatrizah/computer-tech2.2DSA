#include <iostream>
#include <string>

using namespace std;

const int MAX_STUDENTS = 40;

class Grade {
public:
    int mark;
    char the_grade;
};

class Student {
private:
    string reg_number;
    string name;
    int age;
    Grade grade;

public:
    void setRegistrationNumber(const string& regNum) {
        reg_number = regNum;
    }

    void setName(const string& studentName) {
        name = studentName;
    }

    void setAge(int studentAge) {
        age = studentAge;
    }

    void setGrade(const Grade& g) {
        grade = g;
    }

    string getRegistrationNumber() const {
        return reg_number;
    }

    string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    Grade getGrade() const {
        return grade;
    }
};

// Function prototypes
void addStudent(Student students[], int& numStudents);
void editStudent(Student students[], int numStudents);
void addMarks(Student students[], int numStudents);
char calculateGrade(int mark);

int main() {
    Student students[MAX_STUDENTS];
    int numStudents = 0;
    char choice;

    do {
        cout << "Menu:\n";
        cout << "1. Add Student\n";
        cout << "2. Edit Student Details\n";
        cout << "3. Add Marks\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                addStudent(students, numStudents);
                break;
            case '2':
                editStudent(students, numStudents);
                break;
            case '3':
                addMarks(students, numStudents);
                break;
            case '4':
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != '4');

    return 0;
}

void addStudent(Student students[], int& numStudents) {
    if (numStudents < MAX_STUDENTS) {
        Student newStudent;
        string regNum, name;
        int age;

        cout << "Enter registration number: ";
        cin >> regNum;
        newStudent.setRegistrationNumber(regNum);

        cout << "Enter name: ";
        cin.ignore(); // Ignore newline character
        getline(cin, name);
        newStudent.setName(name);

        cout << "Enter age: ";
        cin >> age;
        newStudent.setAge(age);

        students[numStudents++] = newStudent;
        cout << "Student added successfully.\n";
    } else {
        cout << "Maximum number of students reached.\n";
    }
}

void editStudent(Student students[], int numStudents) {
    string regNum;
    cout << "Enter registration number of student to edit: ";
    cin >> regNum;

    for (int i = 0; i < numStudents; ++i) {
        if (students[i].getRegistrationNumber() == regNum) {
            string newName;
            int newAge;

            cout << "Enter new name: ";
            cin.ignore(); // Ignore newline character
            getline(cin, newName);
            students[i].setName(newName);

            cout << "Enter new age: ";
            cin >> newAge;
            students[i].setAge(newAge);

            cout << "Student details updated successfully.\n";
            return;
        }
    }

    cout << "Student not found.\n";
}

void addMarks(Student students[], int numStudents) {
    string regNum;
    cout << "Enter registration number of student to add marks: ";
    cin >> regNum;

    for (int i = 0; i < numStudents; ++i) {
        if (students[i].getRegistrationNumber() == regNum) {
            Grade grade;
            int mark;

            cout << "Enter mark: ";
            cin >> mark;
            grade.mark = mark;
            grade.the_grade = calculateGrade(mark);

            students[i].setGrade(grade);

            cout << "Mark added successfully.\n";
            return;
        }
    }

    cout << "Student not found.\n";
}

char calculateGrade(int mark) {
    if (mark > 69)
        return 'A';
    else if (mark > 59)
        return 'B';
    else if (mark > 49)
        return 'C';
    else if (mark > 39)
        return 'D';
    else
        return 'E';
}
