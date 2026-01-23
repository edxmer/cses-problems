#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, i, s, e;
    cin >> n;
    
    vector<pair<int, int>> modifiers;

    modifiers.reserve(2*n);

    for (i=0; i<n; ++i) {
        cin >> s >> e;
        modifiers.emplace_back(s, 1);
        modifiers.emplace_back(e, -1);
    }
    
    int best = 0;
    int current = 0;

    
    sort(modifiers.begin(), modifiers.end());

    for (auto it = modifiers.begin(); it != modifiers.end(); ++it) {

        current += it->second;
        if (best < current) best = current;
    }

    cout << best << '\n';
    

    return 0;
}
