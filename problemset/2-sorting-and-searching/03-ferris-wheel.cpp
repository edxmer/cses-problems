#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x, i, j, count(0);
    cin >> n >> x;

    vector<int> weights(n);

    for (i=0; i<n; ++i)
        cin >> weights[i];
    
    i=0;
    j=n-1;

    sort(weights.begin(), weights.end());

    while (i <= j) {
        if (weights[j] + weights[i] <= x) {
            ++i;
            --j;
        } else {
            --j;
        }

        ++count;
    } 

    cout << count << '\n';

    return 0;
}
