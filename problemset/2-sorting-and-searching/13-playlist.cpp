#include <iostream>
#include <unordered_map>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, i, best, curr, x;
    cin >> n;

    unordered_map<int, int> m(n); // m[x] = y for the last seen position y of x

    best = 0; // longest distinct sequence so far
    curr = 1; // start of current sequence

    for (i=1; i<=n; ++i) {
        cin >> x;
        if (m.count(x)) {
            if (curr < m[x]+1) curr = m[x]+1;
        }
        m[x] = i;
        if (best < i-curr+1) best = i-curr+1;
    }

    cout << best << '\n';

    return 0;
}
