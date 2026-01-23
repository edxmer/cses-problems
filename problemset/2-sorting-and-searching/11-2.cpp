#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, i, x, rounds;
    cin >> n;
    
    vector<int> v(n+1);

    for (i=1; i<=n; ++i) {
        cin >> x;
        v[x] = i;
    }

    rounds = 1;

    for (i=1; i<n; ++i) {
        if (v[i+1] < v[i])
            ++rounds;
    }

    cout << rounds << '\n';

    
}
