#include <iostream>

using namespace std;


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);


    long long n, i, x, best, sum;
    cin >> n;

    cin >> sum;
    best = sum;

    for (i=1; i<n; ++i) {
        cin >> x;
        if (sum < 0) // sum + x < x
            sum = x;
        else
            sum += x;

        if (best < sum) best = sum;
    }

    cout << best << '\n';

    return 0;
}
