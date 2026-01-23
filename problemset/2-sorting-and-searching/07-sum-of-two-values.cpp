#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x, i, k;
    cin >> n >> x;

    unordered_map<int, int> values(n); // should be enought
    // values, indexes

    for (i=1; i<=n; ++i) {
        cin >> k;
        if (values.count(x-k)) {
            // found it!
            cout << i << ' ' << values[x-k] << '\n';
            return 0;
        }
        values[k] = i;
    }

    cout << "IMPOSSIBLE\n";
    return 0; 
}
