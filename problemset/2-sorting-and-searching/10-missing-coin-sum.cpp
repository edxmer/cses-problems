#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using llu = unsigned long long;

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    llu n, sum;
    cin >> n;

    vector<llu> v(n);
    for (llu &x: v)
        cin >> x;

    sort(v.begin(), v.end());

    sum = 1;
    
    for (llu &x: v) {
        if (sum < x) {
            cout << sum << '\n';
            return 0;
        }
        else
            sum += x;
    }
    cout << sum << '\n';

    return 0;
}
