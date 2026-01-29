#include <iostream>
#include <vector>

using namespace std;

int n, solutions;
vector<int> column, diag1, diag2;


void search(int y) {
    int x;
    if (y==n)
        ++solutions;
    else for (x=0; x<n; ++x) {
        if (column[x] || diag1[x+y] || diag2[n-y-1+x]) continue;
        column[x] = diag1[x+y] = diag2[n-y-1+x] = true;
        search(y+1);
        column[x] = diag1[x+y] = diag2[n-y-1+x] = false;
    }

}


int main(void) {
    cin >> n;

    column = vector<int>(n, false);
    diag1 = vector<int>(n*2-1, false);
    diag2 = vector<int>(n*2-1, false);
    
    solutions = 0;

    search(0);
    
    cout << solutions << '\n';

    return 0;
}
