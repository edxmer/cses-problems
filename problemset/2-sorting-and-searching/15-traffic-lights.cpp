#include <iostream>
#include <set>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int x, n, p, up, down;
    cin >> x >> n;
    
    set<int>::iterator it;
    set<int> lights;
    multiset<int> dists;
    // adding 0 and x, so it won't be necessary to handle edge cases
    lights.insert(0);
    lights.insert(x);
    dists.insert(x);


    for (int i=0; i<n; ++i) {
        cin >> p;
        it = lights.upper_bound(p);

        up = *it;
        --it;
        down = *it;

        dists.erase(dists.find(up-down));
        dists.insert(up-p);
        dists.insert(p-down);
        lights.insert(p);
        

        cout << *dists.rbegin() << ' '; 
    }
    cout << '\n';
    
    return 0;
}
