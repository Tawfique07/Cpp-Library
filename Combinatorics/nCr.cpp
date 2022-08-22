// C++ implementation to find nCr
#include <bits/stdc++.h>
using namespace std;

// Function to find the nCr
uint64_t nCr(int n, int r) {
    if (n < r) {
        return 0;
    }

    uint64_t p = 1, k = 1;

    if (n - r < r) r = n - r;

    if (r != 0) {
        while (r) {
            p *= n;
            k *= r;

            uint64_t m = __gcd(p, k);

            p /= m;
            k /= m;

            n--;
            r--;
        }
    } else {
        p = 1;
    }

    return p;
}

int main() {
    int n, r;
    while (cin >> n >> r) {
        cout << nCr(n, r) << "\n";
    }

    return 0;
}
