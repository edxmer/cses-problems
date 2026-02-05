#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    vector<pair<int, int>> stack(n+1);
    stack.emplace_back(0, 0);
    
    for (int i=1; i<=n; ++i) {
        
        int x;
        cin >> x;

        while (x <= stack.back().first) {
            stack.pop_back();
        }

        cout << stack.back().second << ' ';

        stack.emplace_back(x, i);
    }
    cout << '\n';

    return 0;
}
