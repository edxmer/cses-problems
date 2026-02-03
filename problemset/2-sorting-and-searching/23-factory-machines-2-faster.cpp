#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

vector<int> machines;
constexpr ll UPPER_LIMIT = 2'000'000'000'000'000'001;

ll time_to_products(ll t) {
    ll products = 0;
    ll x;
    for (auto &machine: machines) {
        x = t/machine;
        if (UPPER_LIMIT - products < x)
            return UPPER_LIMIT;
        else
            products += x;
    }
    return products;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, goal;
    cin >> n >> goal;

    machines = vector<int>(n);

    for (auto &machine: machines) {
        cin >> machine;
    }

    ll lower=0, upper=UPPER_LIMIT;
    ll ans;
    while (lower <= upper) {
        ll middle = lower + (upper - lower)/2;

        if (goal <= time_to_products(middle)) {
            ans = middle;
            upper = middle-1;
        }
        else {
            lower = middle+1;
        }
    }

    cout << ans << '\n';

    return 0;
}
