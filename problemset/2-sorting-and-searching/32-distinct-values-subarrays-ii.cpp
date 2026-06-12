#include <iostream>
#include <unordered_map>
#include <vector>
using ll = long long;
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    
    ll solutions = 0;

    vector<int> v(n);
    int distinct_count = 0;
    int j = 0;
    unordered_map<int, int> m(n);

    for (int i=0; i<n; ++i) {
        cin >> v[i];

        
        ++m[v[i]];
        if (m[v[i]] == 1) {
            ++distinct_count;
        }


        while (k < distinct_count) {
            --m[v[j]];
            if (m[v[j]] == 0)
                --distinct_count;
            ++j;
        }

        solutions += i-j+1;
    }

    cout << solutions << '\n';

    
    return 0;
}
