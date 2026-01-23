#include <iostream>
#include <stdexcept>

using namespace std;

class A_Z_map {
    
    int xs[26];

    public:
        A_Z_map() {
            for (auto &x: xs) {
                x = 0;
            }
        }

        void push(const char c) {
            if (c < 'A' || 'Z' < c)
                throw runtime_error("Error: non A-Z character submitted.");
            else
                ++xs[(int)c-(int)'A'];
        }

        int get_even() {
            // Get the first available even, then remove 2
            for (int i = 0; i < 26; ++i) {
                if (0 < xs[i] && xs[i] % 2 == 0) {
                    xs[i] -= 2;
                    return (char)((int)'A'+i);
                }
            }
            throw runtime_error("Error in function get_even.");
        }
        
        int get_odd() {
            // Get the first available odd, then remove 1
            for (int i = 0; i < 26; ++i) {
                if (0 < xs[i] && xs[i] % 2 == 1) {
                    --xs[i];
                    return (char)((int)'A'+i);
                }
            }
            throw runtime_error("Error in function get_odd.");
        }

        int odd_count() const {
            int count = 0;
            for (const auto x: xs) {
                if (x%2 == 1)
                    ++count;
            }

            return count;
        }

};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    int i, mid;
    char c;
    A_Z_map m;

    cin >> s;

    int n = s.length();

    for (const char &c: s) {
        m.push(c);
    }

    if (n % 2 == 0) /* even count, everything needs to be even */ {
        if (m.odd_count() == 0) /* possible */ {
            mid = n/2;
            for (i=0; i<mid; ++i) {
                c = m.get_even();
                s[i] = c;
                s[n-1-i] = c;
            }
            cout << s << '\n';

        } else /* not possible */ {
            cout << "NO SOLUTION\n";
        }
    } else /* odd count, everything except 1 needs to be even*/ {
        if (m.odd_count() == 1) /* possible */ {
            mid = n/2;
            s[mid] = m.get_odd();
            for (i=0; i<mid; ++i) {
                c = m.get_even();
                s[i] = c;
                s[n-1-i] = c;
            }
            cout << s << '\n';
        } else {
            cout << "NO SOLUTION\n";
        }
    }
    
    return 0;
}
