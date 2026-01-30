#include <iostream>
#include <vector>
#include <algorithm>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

using indexed_multiset_less = tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>;
using indexed_multiset_greater = tree<int, null_type, greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update>;


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

    indexed_multiset_less left_sweep;
    indexed_multiset_greater right_sweep;

    vector<int> is_contained(n);
    vector<int> does_contain(n);

    // check if this is contained in something
    for (int i=0; i<n; ++i) {
        // we want to know the number of previous y values that are greater equal
        // we need to find the number of items that are greater equal,
        // so we can use order_of_key, which returns the count of items that are
        // strictly smaller:
        y = ranges[i].y;
        is_contained[ranges[i].i] = left_sweep.size()-left_sweep.order_of_key(y);
        left_sweep.insert(y);
    }

    for (int i=n-1; 0<=i; --i) {
        // we want to know the previous y values that are smaller equal
        // we need to find the largest that is smaller equal,
        // and then the answer will be size()-order_of_key()
        // 9 7 5 _4_ 3 2 1   size=7    7-3=4
        y = ranges[i].y;
        does_contain[ranges[i].i] = right_sweep.size()-right_sweep.order_of_key(y);
        right_sweep.insert(y);
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
