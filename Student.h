#ifndef STUDENT_H
#define STUDENT_H

#include <string>

// Define a structure for a Student node
struct Student {
    int roll_no;
    std::string name;
    int attendanceCount; // Numerical attendance record
    Student* next;
};

// Function declarations
Student* createStudent(int roll_no, std::string name);
void updateRollNumbers(Student* head);
void insertStudent(Student*& head, std::string name);
void takeAttendance(Student* head);
void displayStudentRecord(Student* head, std::string name);
void deleteStudentRecord(Student*& head, std::string name);
void displayAllRecords(Student* head);
void saveToFile(Student* head, const std::string& filename);
void loadFromFile(Student*& head, const std::string& filename);

#endif
