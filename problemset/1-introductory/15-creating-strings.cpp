#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

using stringset = set<string>;

void recursive_swap(string &str, stringset &s, int end) {
    int i;
    s.insert(str);
    for (i=0; i<end; ++i) {
        if (str[i] != str[end]) {
            recursive_swap(str, s, end-1);
            swap(str[i], str[end]);
            s.insert(str);
            recursive_swap(str, s, end-1);
            swap(str[i], str[end]);
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string str;
    stringset s;
    
    cin >> str;

    recursive_swap(str, s, str.length()-1);

    cout << s.size() << '\n';
    for (auto &x: s) {
        cout << x << '\n';
    }
    
    return 0;
}
