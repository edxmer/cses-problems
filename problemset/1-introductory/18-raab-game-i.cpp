#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n, a, b, i, k, shift;
    vector< pair<int, int> > moves(101);

    cin >> t;

    while (t--) {
        cin >> n >> a >> b;
        k = a+b;
        shift = a;

        if (n<a+b || ((b==0 || a==0) && (a+b != 0))) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";

            for (i=1; i<=k; ++i) {
                moves[i] = {i, (i+shift-1)%k+1};
            }
            for (i=k+1; i<=n; ++i) {
                moves[i] = {i, i};
            }

            for (i=1; i<=n; ++i) {
                cout << moves[i].first << ' ';
            }
            cout << '\n';

            for (i=1; i<=n; ++i) {
                cout << moves[i].second << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}
