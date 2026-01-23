#include <iostream>
#include <cmath>

using namespace std;
using ll = long long;

ll pow5(ll k) {
    ll x = 1;
    while (k--)
        x*=5;
    return x;
}

int main(void) {
    
    // log_5 (10^9) < 13
    constexpr ll precision(13);
    ll n, x, i;

    cin >> n;

    x = 0;

    for (i=1; i<=precision; ++i) {
        x += n / pow5(i);
    }

    cout << x << '\n';

    return 0;
}
