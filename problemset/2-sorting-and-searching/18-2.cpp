#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> v;
    v.reserve(2*n);

    for (int i=1; i<=n; ++i)
        v.emplace_back(i);

    for (int i = 0; (size_t)i < v.size(); ++i) {
        if (i%2)
            cout << v[i] << ' ';
        else
            v.emplace_back(v[i]);
    }
    
    cout << '\n';

    return 0;
}
