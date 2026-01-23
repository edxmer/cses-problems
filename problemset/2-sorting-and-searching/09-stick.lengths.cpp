#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = unsigned long long;

ll dist(const ll a, const ll b) {
    if (a < b) return b-a;
    else       return a-b;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll n, sol(0), goal;
    cin >> n;
    
    vector<ll> values(n);

    for (ll &x: values) {
        cin >> x;
    }

    sort(values.begin(), values.end());

    goal = values[n/2];

    for (ll &x: values) {
        sol += dist(x, goal);
    }

    cout << sol << '\n';

    return 0;
}
