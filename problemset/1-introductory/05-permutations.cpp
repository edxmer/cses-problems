#include<iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    // 1: 1
    // 2: no
    // 3: no
    // 4: 2 4 1 3
    // 5: 2 4 1 3 5

    int n, i;
    cin >> n;

    if (n == 1)
        cout << 1 << '\n';
    else if (2<=n and n<=3)
        cout << "NO SOLUTION" << '\n';
    else {
        for (i=2; i<=n; i+=2)
            cout << i << ' ';
        for (i=1; i<=n; i+=2)
            cout << i << ' ';
        cout << '\n';
    }
    return 0;
}
