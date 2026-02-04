#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// holy shit this is so much faster than the map technique
// like 25 times faster
// crazy
// i'll definitely use this from now on


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    cin >> n >> x;

    vector<pair<int, int>> v;
    v.reserve(n);

    for (int i=1; i<=n; ++i) {
        int a;
        cin >> a;
        v.emplace_back(a, i);
    }

    sort(v.begin(), v.end());

    for (int i=0; i<n; ++i) {
        int y = x - v[i].first;
        int j = i+1;
        int k = n-1;
        while (j < k) {
            int s = v[j].first + v[k].first;
            if (s == y) {
                cout << v[i].second << ' '
                     << v[j].second << ' '
                     << v[k].second << '\n';
                return 0;
            }
            else if (s < y) {
                ++j;
            } else {
                --k;
            }
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}
