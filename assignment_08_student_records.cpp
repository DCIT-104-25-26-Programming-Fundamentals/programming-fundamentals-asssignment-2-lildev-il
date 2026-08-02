// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 8
// =============================================================================
//
// TASK: Student Record Management System
//
// Build a console-based program that stores and manages student information.
// Use a struct to represent each student record containing:
//
//   - name   : the student's full name  (string)
//   - id     : a unique student ID number (int, e.g. 20240001)
//   - scores : a list of scores from multiple assessments (vector<double>)
//
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// Define Student struct
struct Student
{
    string name;
    int id;
    vector<double> scores;
};

// Function to calculate average score
double calculateAverage(const Student& student)
{
    if (student.scores.empty())
    {
        return 0.0;
    }

    double total = 0;

    for (double score : student.scores)
    {
        total += score;
    }

    return total / student.scores.size();
}

// Function to add a student
void addStudent(vector<Student>& students)
{
    Student student;

    cout << "Student name: ";
    cin.ignore();
    getline(cin, student.name);

    cout << "Student ID: ";
    cin >> student.id;

    int numberOfScores;

    cout << "How many scores? ";
    cin >> numberOfScores;

    for (int i = 0; i < numberOfScores; i++)
    {
        double score;

        cout << "Enter score " << i + 1 << ": ";
        cin >> score;

        student.scores.push_back(score);
    }

    students.push_back(student);

    cout << "Student \"" << student.name 
         << "\" added successfully." << endl;
}

// Function to display all students
void displayStudents(const vector<Student>& students)
{
    if (students.empty())
    {
        cout << "No students have been added yet." << endl;
        return;
    }

    cout << "\nStudent Records:\n";

    cout << left << setw(20) << "Name"
         << setw(15) << "ID"
         << setw(25) << "Scores"
         << setw(10) << "Average" << endl;

    cout << "-------------------------------------------------------------" << endl;

    for (const Student& student : students)
    {
        cout << left << setw(20) << student.name
             << setw(15) << student.id;

        for (double score : student.scores)
        {
            cout << score << " ";
        }

        cout << setw(10) << fixed << setprecision(2)
             << calculateAverage(student) << endl;
    }
}

// Function to find and display a student's average
void findAverageByID(const vector<Student>& students)
{
    int id;

    cout << "Enter student ID: ";
    cin >> id;

    for (const Student& student : students)
    {
        if (student.id == id)
        {
            cout << student.name << "'s average score: "
                 << fixed << setprecision(2)
                 << calculateAverage(student) << endl;
            return;
        }
    }

    cout << "Error: Student ID not found." << endl;
}

// Function to display menu
void displayMenu()
{
    cout << "\n================================" << endl;
    cout << "   STUDENT RECORD SYSTEM MENU" << endl;
    cout << "================================" << endl;
    cout << "1. Add student" << endl;
    cout << "2. Display all students" << endl;
    cout << "3. Calculate average score" << endl;
    cout << "4. Quit" << endl;
    cout << "Enter your choice (1-4): ";
}

int main()
{
    vector<Student> students;
    int choice;

    do
    {
        displayMenu();
        cin >> choice;

        switch (choice)
        {
            case 1:
                addStudent(students);
                break;

            case 2:
                displayStudents(students);
                break;

            case 3:
                findAverageByID(students);
                break;

            case 4:
                cout << "Goodbye!" << endl;
                break;

            default:
                cout << "Error: Invalid choice. Please select 1-4." << endl;
        }

    } while (choice != 4);

    return 0;
}

