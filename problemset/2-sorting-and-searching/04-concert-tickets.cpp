#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, i, t;
    set<int>::iterator it_t;
    cin >> n >> m;

    multiset<int, greater<int>> t_prices;
    vector<int> c_prices(m);
    

    for (i=0; i<n; ++i) {
        cin >> t;
        t_prices.insert(t);
    }
    for (i=0; i<m; ++i)
        cin >> c_prices[i];


    for (i = 0; i<m; ++i) {
        // i need to find the first item that is less or equal to c_prices[i], then remove it
        it_t = t_prices.lower_bound(c_prices[i]);
        if (it_t != t_prices.end()) {
            c_prices[i] = *it_t;
            t_prices.erase(it_t);
        }
        else {
            c_prices[i] = -1;
        }
    }

    for (auto &x: c_prices)
        cout << x << '\n';

    return 0;
}
