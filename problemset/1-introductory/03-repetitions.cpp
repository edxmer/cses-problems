#include <iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int best, k;
    string s;
    char prev;

    prev = '\0';

    cin >> s;

    for (const char &c: s) {
        
        if (c == prev) {
           ++k; 
        } else {
          k = 1;  
        }

        if (k > best) best = k;

        prev = c;
    }

    cout << best << '\n';

    return 0;
}
