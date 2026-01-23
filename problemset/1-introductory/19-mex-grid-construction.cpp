#include <iostream>
#include <vector>
#include <set>

using namespace std;

int get_best(vector<vector<int> > &grid,const int i,const int j) {
    set<int> s;
    int k;

    for (k=0; k<j; ++k) {
        s.insert(grid[i][k]);
    }
    for (k=0; k<i; ++k) {
        s.insert(grid[k][j]);
    }
    
    k = 0;
    while (s.count(k)) ++k;

    return k;
}

void solve(vector<vector<int> > &grid, const int n) {
    if (n == 1)
        return;

    solve(grid, n-1);

    int j, best;

    for (j=0; j<n; ++j) {
        best = get_best(grid, n-1, j);
        grid[n-1][j] = best;
        grid[j][n-1] = best;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    vector<vector<int> > grid(n, vector<int>(n, 0));

    solve(grid, n);

    for (auto &row: grid) {
        for (auto &x: row)
            cout << x << ' ';
        cout << '\n';
    }

    return 0;
}
