#include <iostream>

using namespace std;

int main(void) {
    int n, i, j;
    cin >> n;

    vector<int> items(n);

    for (i=0; i<n; ++i)
        cin >> items[i];

    for (i=0; i<(1<<n); ++i) {
        vector<int> subset;

        for (j=0; j<n; ++j) if (i&(1<<j))
            subset.push_back(items[j]);

        for (auto &x: subset)
            cout << x << ' ';
        cout << '\n';
    }
}
