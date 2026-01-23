#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    cin >> n;
    vector<int> v;
    v.reserve(n);
    v.push_back(0);

    for (int i=0; i<n; ++i) {
        cin >> x;
        if (v.back() <= x) {
            v.push_back(x);
        } else {
            const auto it ( upper_bound(v.begin(), v.end(), x) );
            *it = x;
        }
    }

    cout << v.size() - 1 << '\n';


    return 0;
}
