#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    size_t i;
    vector<int> xs;

    const int k = 5;


    cin >> n;
    for(i=0; i<(size_t)n; ++i) {
        cin >> x;
        xs.push_back(x);
    }


    sort(xs.begin(), xs.end()); 
    
    vector<int>::iterator s   = lower_bound(xs.begin(), xs.end(), k);
    if (*s != k)
        throw runtime_error("Not found!");

    auto s_er  = equal_range(xs.begin(), xs.end(), k);
    int s_c = s_er.second - s_er.first;


    for (auto x: xs) {
        cout << x << ' ';
    }
    cout << '\n';
    cout << k << " found at index " << (int)(s - xs.begin()) << ", and the count is " << (int)s_c << '\n';

    return 0;
}
