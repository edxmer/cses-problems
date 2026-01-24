#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

using ll = long long;


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n, x, count(0), start(0);
    cin >> n;

    unordered_map<ll, ll> m(n); // item -> last seen position

    for (ll i=0; i<n; ++i) {
        cin >> x;
        if (m.count(x)) {
            start = max(start, m[x]+1);
        }
        m[x] = i;
        
        count += i - start + 1;
    }

    cout << count << '\n';

    return 0;
}
