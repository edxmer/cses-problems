#include <iostream>
#include <vector>
using namespace std;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;

vvb visited;
int solutions;
int n;

void solve(int x, int y, int step) {

    // -- check possibility of step

    if (visited[x][y])
        return;

    // check if 2 are free, and 2 are taken, and also that the takens and non takens are opposite each other
    if ((int)visited[x+1][y] + (int)visited[x-1][y] + (int)visited[x][y+1] + (int)visited[x][y-1] == 2 
        && visited[x+1][y] == visited[x-1][y])
        return;

    if (x == n && y == n) {
        if (step == 49)
            ++solutions;
        return;
    }

    // -- do backtracking

    visited[x][y] = true;

    solve(x+1, y, step+1);
    solve(x-1, y, step+1);
    solve(x, y+1, step+1);
    solve(x, y-1, step+1);

    visited[x][y] = false;

    
}

int main(void) {
    n = 7;

    visited = vvb(n+2, vb(n+2, true));
    for (int i=1; i<=n; ++i) for (int j=1; j<=n; ++j)
        visited[i][j] = false;
    solutions = 0;

    visited[1][1] = true;
    solve(1, 2, 2);
    solutions *= 2;

    cout << solutions << '\n';


    return 0;
}
