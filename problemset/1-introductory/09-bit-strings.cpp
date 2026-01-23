#include <iostream>

using namespace std;
using llu = long long unsigned;

constexpr llu M = 1'000'000'007;

int main(void) {
    
    llu n, x;
    cin >> n;
    x = 1;
    while (n--) {
        x*=2;
        x%=M;
    }

    cout << x << '\n';

    return 0;
}
