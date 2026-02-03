#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
constexpr ll MAX_SOLUTION = 1'000'000'000'000'000'000;
constexpr ll MAX_N = 200'000;

vector<ll> machines(MAX_N);
ll goal;
int n;

bool check(ll t) {
    ll products = 0;
    for (int i = 0; i<n; ++i) {
        products += t / machines[i];
        if (products >= goal)
            return true;
    }
    return false;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> goal;

    for (int i=0; i<n; ++i) {
        cin >> machines[i];
    }

    ll k = 0;
    for (ll b = MAX_SOLUTION; 1<=b; b/=2) {
        while (!check(k+b)) k+=b;
    } // finds the largest k such that k is not a solution -> k+1 is the smallest solution

    cout << k+1 << '\n';
    
    return 0;
}
