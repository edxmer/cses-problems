#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

constexpr int MAXN = 200000;

using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;

    cin >> n >> k;

    if (n==1) {
        cout << 1 << '\n';
        return 0;
    }

    indexed_set s;

    for (int i=1; i<=n; ++i) {
        s.insert(i);
    }
    
    int remaining = n;
    int current = 0;

    while (0 < remaining) {
        current = (current + k) % remaining;
        auto x = s.find_by_order(current);
        cout << *x << ' ';
        s.erase(x);
        --remaining;
    }

    cout << '\n';

    return 0;
}
