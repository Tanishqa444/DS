
#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

double measure(function<void()> operation, int repeats = 5) {
    vector<double> times;

    for (int i = 0; i < repeats; i++) {
        auto start = chrono::high_resolution_clock::now();

        operation();

        auto end = chrono::high_resolution_clock::now();

        chrono::duration<double> elapsed = end - start;
        times.push_back(elapsed.count());
    }

    sort(times.begin(), times.end());

    int n = times.size();

    if (n % 2 == 1)
        return times[n / 2];
    else
        return (times[n / 2 - 1] + times[n / 2]) / 2.0;
}

int main() {
    volatile long long sum = 0;

    double time = measure([&]() {
        for (int i = 0; i < 1000000; i++) {
            sum = sum + i;
        }
    });

    cout << "Median execution time: " << time << " seconds\n";

    return 0;
}
#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<double> times;
    volatile long long sum = 0;

    // Run 5 times
    for (int j = 0; j < 5; j++) {

        sum = 0;

        auto start = chrono::high_resolution_clock::now();

        for (int i = 0; i < 1000000; i++) {
            sum = sum + i;
        }

        auto stop = chrono::high_resolution_clock::now();

        auto time =
            chrono::duration_cast<chrono::microseconds>(
                stop - start
            );

        times.push_back(time.count());
    }

    // Sort execution times
    sort(times.begin(), times.end());

    // Find median
    int n = times.size();
    double median;

    if (n % 2 == 1)
        median = times[n / 2];
    else
        median = (times[n / 2 - 1] + times[n / 2]) / 2.0;

    cout << "Median execution time = "
         << median << " microseconds";

    return 0;
}
