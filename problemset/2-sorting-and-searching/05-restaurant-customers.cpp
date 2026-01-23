#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, i;
    cin >> n;
    
    vector<pair<int, int> > times(n);
    set<int> ends;

    for (i=0; i<n; ++i)
        cin >> times[i].first >> times[i].second;
    
    int solution = 0;

    
    sort(times.begin(), times.end());

    for (i=0; i<n; ++i) {
        ends.insert(times[i].second);
        while (*ends.begin() < times[i].first)
            ends.erase(ends.begin());

        if (solution < (int)ends.size()) solution = ends.size();
    }


    cout << solution << '\n';
    

    return 0;
}
