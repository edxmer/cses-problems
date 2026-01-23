#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*void push_q(queue<pair<int, int> > &q, vector<vector> int n, int i, int j) {
    if (0<=i && i<n && 0<=j && j<n && )
}*/

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, i, j, k;
    pair<int, int> current;
    cin >> n;

    vector<vector<int> > board(n, vector<int>(n, -1));
    queue<pair<int, int> > q;

    auto push_q = [&](int i_, int j_, int k_) { 
        if (0<=i_ && i_<n && 0<=j_ && j_<n && board[i_][j_] == -1) {
            board[i_][j_] = k_+1;
            q.push({i_, j_});
        }
    };
    

    board[0][0] = 0;
    q.push({0, 0});

    while (!q.empty()) {
        current = q.front();
        q.pop();
        i = current.first;
        j = current.second;
        k = board[i][j];

        push_q(i+1, j+2, k);
        push_q(i+1, j-2, k);
        push_q(i-1, j+2, k);
        push_q(i-1, j-2, k);
        push_q(i+2, j+1, k);
        push_q(i+2, j-1, k);
        push_q(i-2, j+1, k);
        push_q(i-2, j-1, k);

    }

    for (i=0; i<n; ++i) {
        for (j=0; j<n; ++j)
            cout << board[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}
