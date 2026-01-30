#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct Range {
    int x, y, i;
    Range(int _x, int _y, int _i): x(_x), y(_y), i(_i) {}
};


int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, x, y;
    cin >> n;
    vector<Range> ranges;
    ranges.reserve(n);

    for (int i=0; i<n; ++i) {
        cin >> x >> y;
        ranges.emplace_back(x, y, i);
    }
    
    sort(ranges.begin(), ranges.end(), [](auto &a, auto &b) {
        if (a.x == b.x)
            return b.y < a.y;
        else
            return a.x < b.x;
    });

    int max_y = 0;
    int min_y = 1e9+1;
    vector<int> is_contained(n);
    vector<int> does_contain(n);

    // check if this is contained in something
    for (int i=0; i<n; ++i) {
        // we know that all previous ones had a x that is less/equal than this' x
        // so we only need to check if the max_y is more/equal than this' y, and if it is,
        // then this is contained in something
        is_contained[ranges[i].i] = (int)(ranges[i].y <= max_y);
        max_y = max(max_y, ranges[i].y);
    }

    for (int i=n-1; 0<=i; --i) {
        // we know that all x's after i are larger
        // if the minimum y of them is equal/smaller than the current's, then this containes something
        does_contain[ranges[i].i] =  (int)(min_y <= ranges[i].y);
        min_y = min(min_y, ranges[i].y);
    }

    for (int i=0; i<n; ++i) {
        cout << does_contain[i] << ' ';
    }
    cout << '\n';

    for (int i=0; i<n; ++i) {
        cout << is_contained[i] << ' ';
    }
    cout << '\n';


    return 0;
}
