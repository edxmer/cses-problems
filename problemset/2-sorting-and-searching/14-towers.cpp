#include <iostream>
#include <set>

using namespace std;

int main(void) {
    
    int n, i, x;
    cin >> n; // 1 2 3 4
    
    multiset<int> tops;
    multiset<int>::iterator it;

    
    for (i=0; i<n; ++i) {
        cin >> x;
        it = tops.upper_bound(x); // smallest element that is larger than x
        if (it != tops.end()) {
            tops.erase(it);
        }
        tops.insert(x);
    }

    cout << tops.size() << '\n';

    return 0;
}
