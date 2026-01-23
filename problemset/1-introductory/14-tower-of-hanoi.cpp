#include <iostream>
#include <cmath>

using namespace std;

void print(int from, int to) {
    cout << from << ' ' << to << '\n';
}

void move(int n, int a, int b, int c) {
    // movest n rings from stack a to stack b using stack c
    // assumption: all other rings are bigger
    
    if (n == 1)
    {
        print(a, b);
    }
    else
    {
        move(n-1, a, c, b);
        move(1, a, b, c);
        move(n-1, c, b, a);
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    cout << pow(2, n) - 1 << '\n';

    move(n, 1, 3, 2);

    return 0;
}
