// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 5
// =============================================================================
//
// TASK: Fibonacci Sequence Generator
//
// The Fibonacci sequence is a series of numbers where each number is the sum
// of the two numbers before it:
//
//   0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
//
// Write a C++ program with TWO parts, each implemented as a function.
//
#include <iostream>
using namespace std;

// Part A: Print the first N Fibonacci terms
void printFibonacci(int n)
{
    if (n <= 0)
    {
        cout << "Error: Number of terms must be positive." << endl;
        return;
    }

    int first = 0, second = 1, next;

    cout << "Fibonacci sequence: ";

    for (int i = 1; i <= n; i++)
    {
        if (i == 1)
        {
            cout << first << " ";
        }
        else if (i == 2)
        {
            cout << second << " ";
        }
        else
        {
            next = first + second;
            cout << next << " ";

            first = second;
            second = next;
        }
    }

    cout << endl;
}

// Part B: Check whether a number is a Fibonacci number
void checkFibonacci(int number)
{
    if (number < 0)
    {
        cout << number << " is NOT a Fibonacci number." << endl;
        return;
    }

    int first = 0, second = 1, next;

    while (first < number)
    {
        next = first + second;
        first = second;
        second = next;
    }

    if (first == number)
    {
        cout << number << " is a Fibonacci number." << endl;
    }
    else
    {
        cout << number << " is NOT a Fibonacci number." << endl;
    }
}

int main()
{
    int n, number;

    // Part A
    cout << "How many terms? ";
    cin >> n;

    printFibonacci(n);

    // Part B
    cout << "\nEnter a number to check: ";
    cin >> number;

    checkFibonacci(number);

    return 0;
}

