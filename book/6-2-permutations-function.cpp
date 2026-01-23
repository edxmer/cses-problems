#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    int n, i;
    cin >> n;
    
    vector<int> permutation(n);

    for(i=0; i<n; ++i)
        cin >> permutation[i];
    
    do {
        for (auto &x: permutation)
            cout << x << ' ';
        cout << '\n';
    } while (next_permutation(permutation.begin(), permutation.end()));

    return 0;
}
