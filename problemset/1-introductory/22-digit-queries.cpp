#include <iostream>
#include <string>

using namespace std;

using ull = long long;


ull pow(ull a, ull n) {
    if (n == 0)
        return 1;

    ull x = a;


    while (--n)
        x*=a;

    return x;
}

ull f(ull n) {
    ull pow10 = pow(10, n);

    return n*pow10 - (pow10 - 1) / 9;
}



int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ull q, x, n, lower_boundary, bound_nth, bound_num_pos, bound_digit_pos;
    cin >> q;

    while (q--) {
        cin >> x;

        n = 0;
        while (f(n) < x)
            ++n;

        lower_boundary = f(n-1);
        

        bound_nth = x - lower_boundary;

        bound_num_pos = (bound_nth-1)/n; // bound_nth/n rounded up
        
        bound_digit_pos = (bound_nth - 1) % n;

        
        cout << to_string(pow(10, n-1) + bound_num_pos)[bound_digit_pos] << '\n';
    }

    return 0;
}
