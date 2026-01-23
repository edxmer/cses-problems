#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, i, j, x, s;
    cin >> n >> x;
    vector<pair<int, int>> v(n);

    for (i=0; i<n; ++i) {
        cin >> v[i].first;
        v[i].second = i+1;
    }


    sort(v.begin(), v.end());


    i = 0;
    j = n-1;
    while (i<j) {
        s = v[i].first+v[j].first;
        if (s==x) {
            cout << v[i].second << ' ' << v[j].second << '\n';
            return 0;
        }
        else {
            if (x < s) // need a smaller sum
                --j;
            else // need a bigger sum
                ++i;
        }
    }
    cout << "IMPOSSIBLE\n";
    

    return 0;
}
