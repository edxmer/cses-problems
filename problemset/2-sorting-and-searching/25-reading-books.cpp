#include <iostream>
#include <algorithm>
using ll = long long;
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    ll sum(0), largest(0);
    cin >> n;
    
    for (int i=0; i<n; ++i) {
        ll x;
        cin >> x;
        sum += x;
        if (largest < x) largest = x;
    }

    cout << max(sum, largest*2) << '\n';
    
    return 0;
}
