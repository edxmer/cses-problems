#include <iostream>
#include <vector>
using namespace std;

/*
    Tudjuk:
        sum(i..j) = sum(j) - sum(i-1)
    Amit akarunk:
        0 = (sum(j)-sum(i-1)) % n
    De ez csak akkor lehetséges, ha sum(j) kongurens sum(i-1)-el, modulo n, tehát:
        sum(i-1) % n = sum(j) % n
    Tehát le kell menteni az előző összegeket modulo n
    (a+b)%n = a%n + b%n
*/

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    long long n;
    cin >> n;
    long long solutions=0, sum=0;

    vector<long long> sums_mod(n);
    sums_mod[0] = 1;

    for (int i=0; i<n; ++i) {
        long long a;
        cin >> a;
        sum += a;

        sum %= n;
        sum += n;
        sum %= n;

        solutions += sums_mod[sum];

        ++sums_mod[sum];
    }

    cout << solutions << '\n';

    return 0;
}
