#include <iostream>

using llu = unsigned long long;
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    llu t, a, b, k, x;

    cin >> t;

    while (t--) {
        cin >> a >> b;
        k = 2*b - a;
        x = k/3;
        if (k%3==0 && 0 <= x && 2*x <= b)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

}
