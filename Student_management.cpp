#include <iostream>
#include <fstream>
using namespace std;

struct student {
    int roll;
    char name[50];
    float marks;
};

class student_record {
public:
    void add_student() {
        student s;
        ofstream fout("students.dat", ios::app);

        cout << "Enter Roll Number: ";
        cin >> s.roll;
        cout << "Enter Name: ";
        cin >> s.name;
        cout << "Enter Marks: ";
        cin >> s.marks;

        fout.write((char*)&s, sizeof(s));
        fout.close();

        cout << "Student record added successfully\n";
    }

    void display_all() {
        student s;
        ifstream fin("students.dat");

        if (!fin) {
            cout << "No records found\n";
            return;
        }

        cout << "\nRoll\tName\tMarks\n";
        while (fin.read((char*)&s, sizeof(s))) {
            cout << s.roll << "\t" << s.name << "\t" << s.marks << endl;
        }
        fin.close();
    }

    void search_student(int r) {
        student s;
        ifstream fin("students.dat");
        bool found = false;

        while (fin.read((char*)&s, sizeof(s))) {
            if (s.roll == r) {
                cout << "Record Found:\n";
                cout << "Roll: " << s.roll << endl;
                cout << "Name: " << s.name << endl;
                cout << "Marks: " << s.marks << endl;
                found = true;
                break;
            }
        }
        fin.close();

        if (!found)
            cout << "Student not found\n";
    }

    void delete_student(int r) {
        student s;
        ifstream fin("students.dat");
        ofstream fout("temp.dat");
        bool found = false;

        while (fin.read((char*)&s, sizeof(s))) {
            if (s.roll != r)
                fout.write((char*)&s, sizeof(s));
            else
                found = true;
        }

        fin.close();
        fout.close();

        remove("students.dat");
        rename("temp.dat", "students.dat");

        if (found)
            cout << "Record deleted successfully\n";
        else
            cout << "Student not found\n";
    }
};

int main() {
    student_record obj;
    int choice, roll;

    while (true) {
        cout << "\n--- Student Record System ---\n";
        cout << "1. Add Student\n";
        cout << "2. Display All\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            obj.add_student();
            break;
        case 2:
            obj.display_all();
            break;
        case 3:
            cout << "Enter roll number: ";
            cin >> roll;
            obj.search_student(roll);
            break;
        case 4:
            cout << "Enter roll number: ";
            cin >> roll;
            obj.delete_student(roll);
            break;
        case 5:
            return 0;
        default:
            cout << "Invalid choice\n";
        }
    }
}
