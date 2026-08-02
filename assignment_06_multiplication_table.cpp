// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 6
// =============================================================================
//
// TASK: Multiplication Table Generator
//
// Write a C++ program that generates multiplication tables using loops
// and functions.
//
#include <iostream>
using namespace std;

// Part A: Print a single multiplication table
void printTable(int number)
{
    cout << "Multiplication Table for " << number << ":" << endl;

    for (int i = 1; i <= 12; i++)
    {
        cout << number << "  x  " << i << "  =  " << number * i << endl;
    }
}

// Part B: Print multiplication tables from 1 to N
void printTablesUpToN(int n)
{
    for (int number = 1; number <= n; number++)
    {
        cout << "\nMultiplication Table for " << number << ":" << endl;

        for (int i = 1; i <= 12; i++)
        {
            cout << number << "  x  " << i << "  =  " 
                 << number * i << endl;
        }

        cout << "---------------------------" << endl;
    }
}

int main()
{
    int number;

    // Part A
    cout << "Enter a number for multiplication table: ";
    cin >> number;

    if (number <= 0)
    {
        cout << "Error: Number must be positive." << endl;
        return 0;
    }

    printTable(number);

    // Part B
    int n;

    cout << "\nEnter N for tables from 1 to N: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Error: Number must be positive." << endl;
        return 0;
    }

    printTablesUpToN(n);

    return 0;
}

