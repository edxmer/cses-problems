#include <iostream>
#include <vector>


using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int n, i, x, maxv, curr;
    vector<int> xs;

    maxv = 0;

    cin >> n;
    for (i=0; i<n; ++i) {
        cin >> x;
        cout << x << '\n';
        xs.push_back(x);
    }


    vector<int>::iterator it1, it2;

    
    for (it1 = xs.begin(); it1 != xs.end(); ++it1) {
        curr = *it1;
        if (curr > maxv)
            maxv = curr;
        cout << "start: " << curr << ' ';
        for (it2=it1+1; it2 != xs.end(); ++it2) {
            curr += *it2;
            cout << "curr: " << curr << ' ';
            if (curr > maxv)
                maxv = curr;
        }
        cout << '\n';
    }

    cout << maxv << '\n';



    return 0;

}
