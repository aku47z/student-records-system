#include "Student.h"
#include <iostream>
#include <fstream>

// Function to create a new Student node
Student *createStudent(int roll_no, std::string name)
{
    Student *newStudent = new Student();
    newStudent->roll_no = roll_no;
    newStudent->name = name;
    newStudent->attendanceCount = 0; // Initial attendance count is 0
    newStudent->next = nullptr;
    return newStudent;
}

// Function to update roll numbers based on alphabetical order
void updateRollNumbers(Student *head)
{
    Student *current = head;
    int roll_no = 1;
    while (current != nullptr)
    {
        current->roll_no = roll_no++;
        current = current->next;
    }
}

// Function to insert a student in alphabetical order
void insertStudent(Student *&head, std::string name)
{
    Student *newStudent = createStudent(0, name); // Roll number will be set later

    // Special case for the head end
    if (head == nullptr || head->name > newStudent->name)
    {
        newStudent->next = head;
        head = newStudent;
    }
    else
    {
        // Locate the node before the point of insertion
        Student *current = head;
        while (current->next != nullptr && current->next->name < newStudent->name)
        {
            current = current->next;
        }
        newStudent->next = current->next;
        current->next = newStudent;
    }

    updateRollNumbers(head);
}

// Function to take attendance for all students
void takeAttendance(Student *head)
{
    Student *current = head;
    while (current != nullptr)
    {
        bool isPresent;
        std::cout << "Is " << current->name << " present? (1 for yes, 0 for no): ";
        std::cin >> isPresent;
        if (isPresent)
        {
            current->attendanceCount += 1;
        }
        current = current->next;
    }
}

// Function to display a student record
void displayStudentRecord(Student *head, std::string name)
{
    Student *current = head;
    while (current != nullptr)
    {
        if (current->name == name)
        {
            std::cout << "Roll No: " << current->roll_no << ", Name: " << current->name << ", Attendance Count: " << current->attendanceCount << std::endl;
            return;
        }
        current = current->next;
    }
    std::cout << "Student not found!" << std::endl;
}

// Function to delete a student record
void deleteStudentRecord(Student *&head, std::string name)
{
    if (head == nullptr)
    {
        std::cout << "List is empty!" << std::endl;
        return;
    }

    // Special case for the head end
    if (head->name == name)
    {
        Student *temp = head;
        head = head->next;
        delete temp;
        updateRollNumbers(head);
        return;
    }

    // Locate the node before the point of deletion
    Student *current = head;
    while (current->next != nullptr && current->next->name != name)
    {
        current = current->next;
    }

    if (current->next == nullptr)
    {
        std::cout << "Student not found!" << std::endl;
        return;
    }

    Student *temp = current->next;
    current->next = current->next->next;
    delete temp;
    updateRollNumbers(head);
}

// Function to display all student records
void displayAllRecords(Student *head)
{
    Student *current = head;
    while (current != nullptr)
    {
        std::cout << "Roll No: " << current->roll_no << ", Name: " << current->name << ", Attendance Count: " << current->attendanceCount << std::endl;
        current = current->next;
    }
}

// Function to save all student records to a file
void saveToFile(Student *head, const std::string &filename)
{
    std::ofstream outFile(filename);
    if (!outFile)
    {
        std::cout << "Error opening file for writing!" << std::endl;
        return;
    }

    Student *current = head;
    while (current != nullptr)
    {
        outFile << current->roll_no << "," << current->name << "," << current->attendanceCount << std::endl;
        current = current->next;
    }
    outFile.close();
    std::cout << "Records saved to " << filename << std::endl;
}

// Function to load student records from a file
void loadFromFile(Student *&head, const std::string &filename)
{
    std::ifstream inFile(filename);
    if (!inFile)
    {
        std::cout << "Error opening file for reading!" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(inFile, line))
    {
        int roll;
        std::string name;
        int attendance;
        size_t pos1 = line.find(',');
        size_t pos2 = line.rfind(',');
        roll = std::stoi(line.substr(0, pos1));
        name = line.substr(pos1 + 1, pos2 - pos1 - 1);
        attendance = std::stoi(line.substr(pos2 + 1));

        insertStudent(head, name);
        head->attendanceCount = attendance;
    }
    inFile.close();
    updateRollNumbers(head);
    std::cout << "Records loaded from " << filename << std::endl;
}
