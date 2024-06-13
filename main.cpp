#include <iostream>
#include "Student.h"

using namespace std;

int main()
{
    Student *head = nullptr;
    int choice;
    string name;

    cout << "\n|| Welcome to Student Records ||\nThis is a terminal application to record students in a class, assign roll no. automatically, take attendance and display their attendance records.";

    cout << "\n\nDo you want to load existing student records from a file? (1 for yes, 0 for no): ";
    cin >> choice;

    if (choice == 1)
    {
        string filename;
        cout << "\nEnter the filename: ";
        cin >> filename;
        loadFromFile(head, filename);
    }
    else
    {
        int totalStudents;
        // Ask for the total number of students at the beginning
        cout << "\nEnter total number of students: ";
        cin >> totalStudents;
        cout << '\n';

        // Insert students until the total number is met
        for (int i = 0; i < totalStudents; ++i)
        {
            cout << "Enter student name: ";
            cin >> name;
            insertStudent(head, name);
        }
    }

    while (true)
    {
        cout << "\n1. Insert Student\n2. Take Attendance\n3. Display Student Record\n4. Delete Student Record\n5. Display All Records\n6. Save to File\n7. Exit\n";
        cout << "\nEnter your choice: ";
        cin >> choice;
        cout << '\n';

        switch (choice)
        {
        case 1:
            cout << "Enter student name: ";
            cin >> name;
            insertStudent(head, name);
            break;
        case 2:
            takeAttendance(head);
            break;
        case 3:
            cout << "Enter student name: ";
            cin >> name;
            displayStudentRecord(head, name);
            break;
        case 4:
            cout << "Enter student name: ";
            cin >> name;
            deleteStudentRecord(head, name);
            break;
        case 5:
            displayAllRecords(head);
            break;
        case 6:
        {
            string filename;
            cout << "Enter filename to save: ";
            cin >> filename;
            saveToFile(head, filename);
            break;
        }
        case 7:
            return 0;
        default:
            cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}
