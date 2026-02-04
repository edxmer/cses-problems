#include <iostream>
#include <map>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, x;
    cin >> n >> x;
    multimap<int, int> m; // value, index

    for (int i=1; i<=n; ++i) {
        int y;
        cin >> y;
        m.emplace(y, i);
    }

    for (auto p=m.begin(); p!=m.end(); ++p) {
        auto q = p;
        ++q;
        for (;q!=m.end() && p->first + q->first <= x; ++q) {
            if (p->second != q->second) {
                int s = x - p->first - q->first;
                auto r = m.upper_bound(s);
                --r;
                
                if (r->first == s && r->second != p->second && r->second != q->second) {
                    cout << p->second << ' ' << q->second << ' ' << r->second << '\n';
                    return 0;
                }

            }
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}
