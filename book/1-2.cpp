#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int n, i, x, best, sum;
    vector<int> xs;
    vector<int>::iterator it;

    best = 0; sum = 0;

    cin >> n;
    for (i=0; i<n; ++i) {
        cin >> x;
        xs.push_back(x);
    }



    
    for (it = xs.begin(); it != xs.end(); ++it) {
        sum = max(sum+*it, *it);
        best = max(best, sum);
    }

    cout << best << '\n';


    return 0;

}
