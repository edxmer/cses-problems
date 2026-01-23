#include <iostream>
#include <vector>

using namespace std;

constexpr char QUEEN = 'x';
constexpr char RESERVED = '*';
constexpr char FREE = '.';

bool is_valid(vector<string> &board, int i, int j) {
    // check horizontal line and both diagonals to the right
    int k;
    for (k=1; i+k<8; ++k) {
        if (board[j][i+k] == QUEEN
        || ( j+k<8  && board[j+k][i+k] == QUEEN )
        || ( 0<=j-k && board[j-k][i+k] == QUEEN))
        {
            return false;
        }
    }

    return board[j][i] != RESERVED;
}

void solve(vector<string> &board, int &count, int i) {
    int j;
    
    if (i==-1) {
        ++count;   
    }
    else {
        for (j=0; j<8; ++j) {
            if (is_valid(board, i, j)) {
                board[j][i] = QUEEN;
                solve(board, count, i-1);
                board[j][i] = FREE;
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<string> board(8);
    int i, count(0);

    for (i=0; i<8; ++i) {
        cin >> board[i];
    }

    solve(board, count, 7);

    cout << count << '\n';

    return 0;
}
