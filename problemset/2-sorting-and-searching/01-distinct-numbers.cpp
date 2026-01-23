#include <iostream>
#include <unordered_set>

using namespace std;

int main(void) {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(0);

    unordered_set<int> s(200000);
    int n, x;
    cin >> n;

    while (n--) {
        cin >> x;
        s.insert(x);
    }

    cout << s.size() << '\n';
    return 0;
}
