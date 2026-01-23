#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, i, j, k, s, min_moves_by_dist;
    cin >> n;

    const vector<vector<int> > b4 = {
            {0, 3, 2, 3},
            {3, 4, 1, 2},
            {2, 1, 4, 3},
            {3, 2, 3, 2},
    };
    
    for (i=0; i<n; ++i) {
        for (j=0; j<n; ++j) {
            if (n==4 && ((i==3 && j==0) || (i==0 && j==3)))
                k = 5;
            else if (i<4 && j<4)
                k = b4[i][j];
            else {
                s = i+j;
                if (s%3 == 0) {
                    k = s/3;
                } else if (s%3 == 1) {
                    k = (s+2)/3;
                } else {
                    k = (s+4)/3;
                }
                
                min_moves_by_dist = (max(i, j) + 1) / 2;
                k = max(k, min_moves_by_dist);
                
                if (k % 2 != s % 2) {
                    k++;
                }
            }

            cout << k << ' ';
        }
        cout << '\n';
    }

    return 0;
}
