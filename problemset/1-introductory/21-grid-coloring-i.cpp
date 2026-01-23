#include <iostream>
#include <unordered_set>

using namespace std;

using sc = unordered_set<char>;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, i, j;
    cin >> n >> m;
    
    string lines[1000];

    for (i=0; i<n; ++i) {
        cin >> lines[i];
    }

    for (i=0; i<n; ++i) for (j=0; j<m; ++j) {
         sc set = {'A', 'B', 'C', 'D'};

        if (0<i)
            set.erase(lines[i-1][j]);
        
        if (0<j)
            set.erase(lines[i][j-1]);
        
        set.erase(lines[i][j]);

        lines[i][j] = *set.begin();
    }


    for (i=0; i<n; ++i) {
        for (j=0; j<m; ++j)
            cout << lines[i][j];
        cout << '\n';
    }

    return 0;
}
