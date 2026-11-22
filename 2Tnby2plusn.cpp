
#include <iostream>
#include <chrono>
using namespace std;

void solve(int n) {
    if (n <= 1)
        return;

    solve(n / 2);
    solve(n / 2);

    volatile long long x = 0;

    for (int i = 0; i < n; i++) {
        x++;
    }
}

int main() {
    int n;
    cin >> n;

    auto start = chrono::high_resolution_clock::now();

    solve(n);

    auto stop = chrono::high_resolution_clock::now();

    auto time =
        chrono::duration_cast<chrono::microseconds>(
            stop - start
        );

    cout << "Time = " << time.count()
         << " microseconds";

    return 0;
}
