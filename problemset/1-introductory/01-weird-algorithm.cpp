#include <iostream>

using ull = unsigned long long;
using namespace std;

int main(void) {
    ull n;

    cin >> n;
    while (n != 1) {
        cout << n << ' ';
        if (n % 2) /* odd */  {
          n*=3;
          ++n;
        } else /* even */ {
            n/=2;
        }
    }
    cout << n << '\n';

    return 0;
}
