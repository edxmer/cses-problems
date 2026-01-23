#include <iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int n, i, x;
    cin >> n;

    int sum = n; // 1 + .. + [n]
    
    for (i=1; i<=n-1; ++i) {
        cin >> x;
        sum+=i-x;
    }

    cout << sum << '\n';

    return 0;
}

