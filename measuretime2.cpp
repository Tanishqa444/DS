
#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <functional>
#include <iomanip>
using namespace std;

double measure(function<void()> operation, int repeats = 5) {
    vector<double> times;

    for (int i = 0; i < repeats; i++) {
        auto start = chrono::steady_clock::now();

        operation();

        auto end = chrono::steady_clock::now();

        chrono::duration<double, milli> elapsed = end - start;
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
    int sizes[] = {1000, 5000, 10000, 50000, 100000};
    int repeats = 10000;
    volatile int result = 0;

    cout << fixed << setprecision(6);

    for (int k = 0; k < 5; k++) {
        int n = sizes[k];

        vector<int> arr(n + 1);

        for (int i = 0; i < n; i++)
            arr[i] = i;

        cout << "\nArray size: " << n << endl;

        double t1 = measure([&]() {
            for (int j = 0; j < repeats; j++) {
                for (int i = n; i > 0; i--)
                    arr[i] = arr[i - 1];

                arr[0] = j;
            }
            result = arr[0];
        });

        double t2 = measure([&]() {
            for (int j = 0; j < repeats; j++) {
                arr[n] = j;
                result = arr[n];
            }
        });

        double t3 = measure([&]() {
            for (int j = 0; j < repeats; j++) {
                for (int i = n; i > n / 2; i--)
                    arr[i] = arr[i - 1];

                arr[n / 2] = j;
            }
            result = arr[n / 2];
        });

        double t4 = measure([&]() {
            for (int j = 0; j < repeats; j++) {
                for (int i = 0; i < n - 1; i++)
                    arr[i] = arr[i + 1];
            }
            result = arr[0];
        });

        double t5 = measure([&]() {
            for (int j = 0; j < repeats; j++) {
                int size = n;
                size--;
                result = size;
            }
        });

        double t6 = measure([&]() {
            for (int j = 0; j < 100; j++) {
                vector<int> newArr(2 * n);

                for (int i = 0; i < n; i++)
                    newArr[i] = arr[i];

                result = newArr[n - 1];
            }
        });

        cout << "Append:           " << t2 << " ms\n";
        cout << "Insert beginning: " << t1 << " ms\n";
        cout << "Insert middle:    " << t3 << " ms\n";
        cout << "Delete beginning: " << t4 << " ms\n";
        cout << "Delete end:       " << t5 << " ms\n";
        cout << "Resize:           " << t6 << " ms\n";
    }

    return 0;
}
