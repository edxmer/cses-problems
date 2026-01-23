#include <iostream>

using namespace std;
using ull = unsigned long long;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    
    ull prev, x, moves(0);
    int n;
    cin >> n >> prev;

    while (--n) /* n-1 repetitions*/ {
        cin >> x;
        if (x<prev)
            moves+=prev-x; // prev stays the same
        else
            prev=x; // prev grows
    }
    
    cout << moves << '\n';

    return 0;
}
