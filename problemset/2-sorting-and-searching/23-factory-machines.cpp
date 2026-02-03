#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

vector<int> machines;
constexpr ll UPPER_LIMIT = 2'000'000'000'000'000'001;

ll time_to_machines(ll t) {
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
    ll middle = (lower+upper)/2;
    ll ttmm = time_to_machines(middle);
    while (!(time_to_machines(middle-1) < goal && goal <= ttmm)) {
        if (goal <= ttmm) {
            upper = middle;
        }
        else {
            lower = middle;
        }

        middle = (lower+upper) / 2;
        ttmm = time_to_machines(middle);
    }

    cout << middle << '\n';

    return 0;
}
