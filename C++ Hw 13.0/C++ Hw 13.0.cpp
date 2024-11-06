#include <iostream>
#include <string.h>

using namespace std;

struct Student {
private:
    char* name;
    char* surname;
    double averageMark;
public:
    Student() {
        name = new char[9] {'B', 'o', 'r', 'y', 's', 'l', 'a', 'v', '\0' };
        surname = new char[11] {'L', 'i', 'n', 'c', 'h', 'e', 'v', 's', 'k', 'y', '\0'};
        averageMark = 11.2;
    }

    void AssingValues(const char* name, const char* surname, double averageMark) {
        delete[] this->name;
        this->name = nullptr;

        delete[] this->surname;
        this->surname = nullptr;

        this->name = new char[strlen(name) + 1];

        for (int i = 0; i < strlen(name) + 1; i++) {
            this->name[i] = (char)name[i];
        }

        this->surname = new char[strlen(surname) + 1];

        for (int i = 0; i < strlen(surname) + 1; i++) {
            this->surname[i] = (char)surname[i];
        }

        this->averageMark = averageMark;
    }

    void setStudentName(const char* studentName) {
        delete[] this->name;
        this->name = nullptr;

        this->name = new char[strlen(studentName) + 1];

        for (int i = 0; i < strlen(studentName) + 1; i++) {
            this->name[i] = (char)studentName[i];
        }
    }

    void setStudentSurname(const char* studentName) {
        delete[] this->surname;
        this->surname = nullptr;

        this->surname = new char[strlen(studentName) + 1];

        for (int i = 0; i < strlen(studentName) + 1; i++) {
            this->surname[i] = (char)studentName[i];
        }
    }

    const char* getName() {
        return name;
    }

    const char* getSurname() {
        return surname;
    }

    double getAverageMark() {
        return averageMark;
    }

    /*~Student() {
        delete[] name;
        name = nullptr;

        delete[] surname;
        surname = nullptr;
    }*/
};

struct Group {
private:
    char* groupName;
    int amountOfStudents;
    Student* arrayOfStudents;
public:
    Group() {
        groupName = new char[4] {'P', '3', '8', '\0'};
        amountOfStudents = 1;
        arrayOfStudents = new Student[1];
        arrayOfStudents[0].AssingValues("Boryslav", "Linchevsky", 11.2);
    }

    void AddStudent(Student student) {
        Student* tempArrOfStudents = new Student[amountOfStudents];

        for (int i = 0; i < amountOfStudents; i++) {
            tempArrOfStudents[i].AssingValues(
                arrayOfStudents[i].getName(),
                arrayOfStudents[i].getSurname(),
                arrayOfStudents[i].getAverageMark());
        }

        delete[] arrayOfStudents;
        arrayOfStudents = nullptr;

        amountOfStudents++;

        arrayOfStudents = new Student[amountOfStudents];

        for (int i = 0; i < amountOfStudents - 1; i++) {
            arrayOfStudents[i].AssingValues(
                tempArrOfStudents[i].getName(),
                tempArrOfStudents[i].getSurname(),
                tempArrOfStudents[i].getAverageMark());
        }

        delete[] tempArrOfStudents;
        tempArrOfStudents = nullptr;

        arrayOfStudents[amountOfStudents - 1].AssingValues(
            student.getName(),
            student.getSurname(),
            student.getAverageMark());
    }

    void ClearStudent(Student student) {
        Student* tempArrOfStudents = new Student[amountOfStudents];

        for (int i = 0; i < amountOfStudents - 1; i++) {
            tempArrOfStudents[i].AssingValues(
                arrayOfStudents[i].getName(),
                arrayOfStudents[i].getSurname(),
                arrayOfStudents[i].getAverageMark());
        }

        amountOfStudents--;

        delete[] tempArrOfStudents;
        tempArrOfStudents = nullptr;
    }

    void PrintGroupInfo() {
        cout << "Group name: " << this->groupName << endl;
        cout << "Amount of students: " << this->amountOfStudents << endl;
        for (int i = 0; i < amountOfStudents; i++) {
            cout << "Student: " << i + 1 << endl;
            cout << "Name: " << this->arrayOfStudents[i].getName() << endl;
            cout << "Surname: " << this->arrayOfStudents[i].getSurname() << endl;
            cout << "Average mark: " << this->arrayOfStudents[i].getAverageMark() << endl;
        }
    }

    const char* getGroupName() {
        return this->groupName;
    }

    void setGroupName(const char* groupName) {
        delete[] this->groupName;
        this->groupName = nullptr;

        this->groupName = new char[strlen(groupName) + 1];

        for (int i = 0; i < strlen(groupName) + 1; i++) {
            this->groupName[i] = (char)groupName[i];
        }
    }

    int getAmountOfStudents() {
        return this->amountOfStudents;
    }

    void setAmountOfStudents(int amountOfStudents) {
        this->amountOfStudents = amountOfStudents;
    }

    Student* getStudentsArray() {
        return this->arrayOfStudents;
    }

    void setStudentsArray(Student* arrayOfStudents, int n) {
        delete[] this->arrayOfStudents;
        this->arrayOfStudents = nullptr;

        this->arrayOfStudents = new Student[n];

        for (int i = 0; i < n; i++) {
            this->arrayOfStudents[i] = (Student)arrayOfStudents[i];
        }
    }

    ~Group() {
        delete[] groupName;
        groupName = nullptr;

        delete[] arrayOfStudents;
        arrayOfStudents = nullptr;
    }
};

int main()
{
    Student obj = Student();

    cout << obj.getName() << endl;
    cout << obj.getSurname() << endl;
    cout << obj.getAverageMark() << endl;

    obj.AssingValues("Ivan", "Ivanov", 8.8);
    cout << obj.getName() << endl;
    cout << obj.getSurname() << endl;
    cout << obj.getAverageMark() << endl;

    Group p38 = Group();

    p38.PrintGroupInfo();

    cout << "Add-----------------------" << endl;
    p38.AddStudent(obj);
    p38.PrintGroupInfo();
    cout << "Delete-----------------------" << endl;
    p38.ClearStudent(obj);
    p38.PrintGroupInfo();
    cout << "Rename-----------------------" << endl;
    char* nameOfStudent = new char [7] {'K', 'i', 'r', 'i', 'l', 'l', '\0'};
    char* surnameOfStudent = new char [11] {'Y', 'a', 'k', 'i', 'b', 'o', 'v', 'i', 'c', 'h', '\0'};
    p38.getStudentsArray()[0].setStudentName(nameOfStudent);
    p38.getStudentsArray()[0].setStudentSurname(surnameOfStudent);
    p38.PrintGroupInfo();
}
