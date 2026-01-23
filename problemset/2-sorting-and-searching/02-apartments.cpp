#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, k, i, j, afront, bfront, solution(0);
    cin >> n >> m >> k;

    vector<int> a(n), b(m);

    for (i=0; i<n; ++i)
        cin >> a[i];
    for (i=0; i<m; ++i)
        cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    i=0;
    j=0;
    
    while (i<n && j<m) {
        afront = a[i];
        bfront = b[j];

        if (afront-k <= bfront && bfront <= afront+k) {
            ++i;
            ++j;
            solution++;
        } else if (afront < bfront)
            ++i;
        else
            ++j;
    }

    cout << solution << '\n';

    return 0;
}
