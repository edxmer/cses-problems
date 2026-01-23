#include <iostream>

using ull = unsigned long long;
using namespace std;

int main(void) {
    
    ull n, i;

    cin >> n;

    cout << 0 << '\n';

    for (i=2; i<=n; ++i) {
        cout << i*i*(i*i-1)/2 - (i-1)*(i-2)*4 << '\n';
    }

    return 0;
}
