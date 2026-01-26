#include <iostream>
#include <unordered_set>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    int k = -1;
    
    unordered_set<int> removed(n);

    while ((int)removed.size() < n) {
        ++k;
        k %= n;
        while (removed.count(k)) {
            ++k;
            k %= n;
        }
        ++k;
        k %= n;
        while (removed.count(k)) {
            ++k;
            k %= n;
        }
        
        cout << k+1 << ' ';
        removed.insert(k);
    }

    cout << '\n';
    return 0;
}
