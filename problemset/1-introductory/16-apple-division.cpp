#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

void compare_sum(vector<ll> &xs, const ll &sum, ll &best) {
    ll a(0), y;

    for (const auto &x: xs) {
        a+=x;
    }
    // b = sum-a
    // abs(a-b) = abs(a-(sum-a)) = abs(a+a-sum)
    
    y = abs(a+a-sum);

    
    if (y < best)
        best = y;
}

void solve(vector<ll> &xs, const ll &sum, ll &best, int i) {
    ll temp;

    if (i==0) {
        compare_sum(xs, sum, best);
        temp = xs[0];
        xs[0] = 0;
        compare_sum(xs, sum, best);
        xs[0] = temp;
    } else {
        solve(xs, sum, best, i-1);
        temp = xs[i];
        xs[i] = 0;
        solve(xs, sum, best, i-1);
        xs[i] = temp;
    }
}

int main(void) {

    vector<ll> xs;
    ll n, i, x, sum(0), best;

    cin >> n;

    xs.reserve(n);

    for (i=0; i<n; ++i) {
        cin >> x;
        sum += x;
        xs.push_back(x);
    }

    best = sum;

    solve(xs, sum, best, n-1);

    cout << best << '\n';
    
    return 0;
}
