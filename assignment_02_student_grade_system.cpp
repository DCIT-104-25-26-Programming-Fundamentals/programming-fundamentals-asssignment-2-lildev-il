// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 2
// =============================================================================
//
// TASK: Student Grade System
//
// Write a C++ program that reads a student's score and outputs the
// corresponding letter grade based on the scale below.
//
#include <iostream>
using namespace std;

// Function to determine the student's grade
char getGrade(int score)
{
    // Validate the score
    if (score < 0 || score > 100)
    {
        return '\0';   // Null character indicates an invalid score
    }

    // Determine the grade
    if (score >= 80)
    {
        return 'A';
    }
    else if (score >= 70)
    {
        return 'B';
    }
    else if (score >= 60)
    {
        return 'C';
    }
    else if (score >= 50)
    {
        return 'D';
    }
    else
    {
        return 'F';
    }
}

int main()
{
    int score;

    cout << "Enter student score (0-100): ";
    cin >> score;

    char grade = getGrade(score);

    if (grade == '\0')
    {
        cout << "Error: Score must be between 0 and 100." << endl;
    }
    else
    {
        cout << "Grade: " << grade << endl;
    }

    return 0;
}
