#include <iostream>
#include <unordered_map>
using namespace std;
using ll = unsigned long long;
constexpr ll M = 1'000'000'007;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n, x, sol=1;
    cin >> n;

    unordered_map<ll, ll> occourences(n);

    for (ll i=0; i<n; ++i) {
        cin >> x;
        ++occourences[x];
    }

    for (auto &o: occourences) {
        sol *= o.second + 1;
        sol %= M;
    }

    cout << sol - 1 << '\n';
    
    return 0;
}
