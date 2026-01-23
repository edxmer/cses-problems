#include <iostream>
#include <unordered_set>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, i, x;
    cin >> n;

    unordered_set<int> s(n);

    for (i=0; i<n; ++i) {
        cin >> x; 
        if (s.count(x-1)) {
            s.erase(x-1);
            s.insert(x);
        }
        else {
            s.insert(x);
        }
    }

    cout << s.size() << '\n';
    
    return 0;
}
