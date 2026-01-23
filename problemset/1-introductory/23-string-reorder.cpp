#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<int> letters(26, 0);
    string str;
    int n, i;
    char k, priority_char;
    bool found, priority;

    cin >> str;
    
    n = str.length();

    for (char c: str) {
        ++letters[c-'A'];
    }

    for (i=0; i<n; ++i) {
        // str[i] = get_first_available_letter(exclude: str[i-1])
        // dont choose a letter if there is something after it with remaining spaces less than its count*2

        found = false;
        priority = false;

        for (k='A'; k<='Z' && !priority; ++k) { // if there are multiple priorities, this is not possible, but
                                                 // idc, it will be picked up within the second for
            if ((n-i)/2 + 1 == letters[k-'A'] && (i == 0 || k != str[i-1])) {
                priority = true;
                priority_char = k;
            }
        }
        

        if (priority) {
            str[i] = priority_char;
            --letters[priority_char-'A'];
            found = true;
        }
        else {
            for (k='A'; k<='Z' && !found; ++k) {
                if (0 < letters[k-'A'] && (i == 0 || k != str[i-1])) {
                        str[i] = k;
                        --letters[k-'A'];
                        found = true;
                }
            }
        }

        if (!found) {
            cout << -1 << '\n';
            return 0;
        }
    }

    cout << str << '\n';

    return 0;
}
