
#include <iostream>
#include <chrono>
using namespace std;

// Q1: Factorial - O(n)
long long factorial(int n) {
    if (n <= 1)
        return 1;

    return n * factorial(n - 1);
}

// Q2: Sum of first n numbers - O(n)
int sum(int n) {
    if (n == 0)
        return 0;

    return n + sum(n - 1);
}

// Q3: Fibonacci - O(2^n)
int fibonacci(int n) {
    if (n <= 1)
        return n;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Q4: Fibonacci with call counter - O(2^n)
long long calls = 0;

int fibonacciCount(int n) {
    calls++;

    if (n <= 1)
        return n;

    return fibonacciCount(n - 1) + fibonacciCount(n - 2);
}

// Q5: Linear recursion - O(n)
// T(n) = T(n-1) + 1
void linearRecursion(int n) {
    if (n <= 0)
        return;

    cout << n << " ";
    linearRecursion(n - 1);
}

// Q6: Divide by 2 - O(log n)
// T(n) = T(n/2) + 1
void divideBy2(int n) {
    if (n <= 1)
        return;

    cout << n << " ";
    divideBy2(n / 2);
}

// Q7: Two recursive calls - O(n)
// T(n) = 2T(n/2) + 1
void twoRecursiveCalls(int n) {
    if (n <= 1)
        return;

    twoRecursiveCalls(n / 2);
    twoRecursiveCalls(n / 2);

    cout << n << " ";
}

// Q8: Two calls + n work - O(n log n)
// T(n) = 2T(n/2) + n
void recursiveNLogN(int n) {
    if (n <= 1)
        return;

    recursiveNLogN(n / 2);
    recursiveNLogN(n / 2);

    volatile long long x = 0;

    for (int i = 0; i < n; i++) {
        x++;
    }
}

// Q9: Count recursion tree nodes - O(n)
long long nodes = 0;

void countNodes(int n) {
    nodes++;

    if (n <= 1)
        return;

    countNodes(n / 2);
    countNodes(n / 2);
}

// Q10 & Q11: Timing experiment - O(n log n)
// Uses recursiveNLogN() from Q8
void measureTime() {
    int sizes[] = {1000, 5000, 10000, 50000, 100000};

    for (int n : sizes) {
        auto start = chrono::high_resolution_clock::now();

        recursiveNLogN(n);

        auto stop = chrono::high_resolution_clock::now();

        auto duration =
            chrono::duration_cast<chrono::microseconds>(
                stop - start
            );

        cout << "n = " << n
             << " Time = " << duration.count()
             << " microseconds" << endl;
    }
}

// ONLY ONE MAIN FUNCTION
int main() {
    int n;

    cout << "Enter n: ";
    cin >> n;

    if (n < 1) {
        cout << "Enter a positive number.";
        return 0;
    }

    // Q1
    cout << "\nQ1 Factorial: " << factorial(n) << endl;

    // Q2
    cout << "\nQ2 Sum: " << sum(n) << endl;

    // Q3
    cout << "\nQ3 Fibonacci: " << fibonacci(n) << endl;

    // Q4
    calls = 0;
    cout << "\nQ4 Fibonacci: " << fibonacciCount(n) << endl;
    cout << "Total calls: " << calls << endl;

    // Q5
    cout << "\nQ5 Linear recursion: ";
    linearRecursion(n);
    cout << endl;

    // Q6
    cout << "\nQ6 Divide by 2: ";
    divideBy2(n);
    cout << endl;

    // Q7
    cout << "\nQ7 Two recursive calls: ";
    twoRecursiveCalls(n);
    cout << endl;

    // Q8
    recursiveNLogN(n);
    cout << "\nQ8 O(n log n) recursion completed" << endl;

    // Q9
    nodes = 0;
    countNodes(n);
    cout << "\nQ9 Total nodes = " << nodes << endl;

    // Q10 & Q11
    cout << "\nQ10 & Q11 Timing Experiment:\n";
    measureTime();

    return 0;
}
