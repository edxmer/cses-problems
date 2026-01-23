#include <iostream>
#include <algorithm>

using namespace std;

using ull = unsigned long long;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    ull y, x, radius, num;

    cin >> t;

    while (t--) /* iterate t times*/ {
        cin >> y >> x;
        radius = max(x, y);

        if (radius % 2) /* odd radius, decrease starting from top right */ {
            num = radius * radius - (y-1) - (radius - x);
        }
        else /*even radius, decrease starting from bottom left*/ {
            num = radius * radius - (x-1) - (radius - y);
        }
        cout << num << '\n';

    }

    return 0;
}
