#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n, i, sum, half;
    cin >> n;
    vector<int> first_set;
    vector<int> second_set;

    first_set.reserve(n);
    second_set.reserve(n);
    
    sum = n*(n+1)/2;
    if (sum%2) /* not divisible by two */ {
        cout << "NO" << '\n';
        return 0;
    }

    half = sum/2;

    for (i=n; 1<=i; --i) {
        if (0 <= half - i) {
            half -= i;
            first_set.push_back(i);
        }
        else {
            second_set.push_back(i);
        }
    }

    cout << "YES" << '\n';
    cout << first_set.size() << '\n';
    for (const auto &x: first_set) {
        cout << x << ' ';
    }
    cout << '\n';
    cout << second_set.size() << '\n';
    for (const auto &x: second_set) {
        cout << x << ' ';
    }
    cout << '\n';


    return 0;
}
