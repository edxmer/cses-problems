#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool are_indexes_unique(pair<int, int> p1, pair<int, int> p2) {
    return p1.first != p1.second
        && p2.first != p2.second // i know the first 2 are always true but ill leave this here anyways
        && p1.first != p2.first
        && p1.second != p2.second
        && p1.first != p2.second
        && p1.second != p2.first;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    vector<pair<int, pair<int, int>>> sum2s;
    sum2s.reserve(n*(n-1)/2);

    for (int i=0; i<n; ++i) {
        cin >> v[i];
    }

    for (int i=0; i<n; ++i) for (int j=i+1; j<n; ++j) {
        sum2s.push_back({v[i]+v[j], {i+1, j+1}});
    }

    sort(sum2s.begin(), sum2s.end());

    int i=0, j=sum2s.size()-1;
    while (i<j) {
        int s = sum2s[i].first + sum2s[j].first;
        if (s == x) {
            int iend  = i+1;
            while (iend < (int)sum2s.size() && sum2s[iend].first == sum2s[i].first) ++iend;
            int jrend = j-1;
            while (0 <= jrend && sum2s[jrend].first == sum2s[j].first) --jrend;

            for (int i2=i; i2!=iend; ++i2) for (int j2=j; j2!=jrend; --j2) {
                if (are_indexes_unique(sum2s[i2].second, sum2s[j2].second)) {
                    cout << sum2s[i2].second.first << ' '
                         << sum2s[i2].second.second << ' '
                         << sum2s[j2].second.first << ' '
                         << sum2s[j2].second.second << '\n';
                    return 0;
                }
            }
            ++i;
            --j;
        }
        else if (s < x) {
            ++i;
        } else {
            --j;
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}
