#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, curr_end_time, count;
    cin >> n;

    vector<pair<int, int>> xs(n);

    for (auto &x: xs)
        cin >> x.first >> x.second;

    sort(xs.begin(), xs.end(), [](auto &a, auto &b){
        return a.second < b.second;
    });

    curr_end_time = 0;
    count = 0;
    for (auto &x: xs) {
        if (curr_end_time <= x.first) {
            ++count;
            curr_end_time = x.second;
        }
    }

    cout << count << '\n';

    return 0;
}
