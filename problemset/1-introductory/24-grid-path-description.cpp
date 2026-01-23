#include <iostream>

using namespace std;

bool taken[9][9];
int solutions = 0;
string base;

void solve(int x, int y, int step) {
    if (x == 1 && y==7 && step==48)
        ++solutions;
    if ((x==1 && y==7) || step==48)
        return;


    taken[x][y] = true;
    
    bool q = base[step] == '?';

    // right
    if ((q or base[step]=='R') && !taken[x+1][y] && !(!taken[x+1][y+1] && !taken[x+1][y-1] && taken[x+2][y]))
        solve(x+1, y, step+1);

    // down
    if ((q or base[step]=='D') && !taken[x][y+1] && !(!taken[x+1][y+1] && !taken[x-1][y+1] && taken[x][y+2])) 
        solve(x, y+1, step+1);

    // left
    if ((q or base[step]=='L') && !taken[x-1][y] && !(!taken[x-1][y-1] && !taken[x-1][y+1] && taken[x-2][y])) 
        solve(x-1, y, step+1);

    // up
    if ((q or base[step]=='U') && !taken[x][y-1] && !(!taken[x-1][y-1] && !taken[x+1][y-1] && taken[x][y-2])) 
        solve(x, y-1, step+1);
 
    taken[x][y] = false;
}

int main(void) {
    int i, j;

    cin >> base;

    for (i=0; i<9; ++i) for (j=0; j<9; ++j)
        taken[i][j] = i<1 or 7<i or j<1 or 7<j;
    
    solve(1, 1, 0);

    cout << solutions << '\n';
    return 0;
}
