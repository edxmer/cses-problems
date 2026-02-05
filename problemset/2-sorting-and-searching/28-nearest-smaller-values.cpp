#include <iostream>
#include <map>

using namespace std;

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    map<int, int> m;
    m[0] = 0;


    for (int i=1; i<=n; ++i) {
        int x;
        cin >> x;
        m[x] = i;
        auto p = m.lower_bound(x);
        --p;
        cout << p->second << ' ';
        ++p;
        ++p;
        m.erase(p, m.end());
    }
    cout << '\n';

    return 0;
}
