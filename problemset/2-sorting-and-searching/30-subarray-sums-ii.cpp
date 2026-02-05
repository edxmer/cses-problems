#include <iostream>
#include <map>
using ll = long long;
using namespace std;

/*
    Tudjuk, hogy ha i<j
        x=sum(i..j)=sum(j)-sum(i-1)
    ezt átrendezve:
        sum(i-1)=sum(j)-x
    Tehát ha valamilyen sum(j)-re létezik egy olyan sum(i-1) hogy ez teljesül,
    akkor az egy megoldás. Mivel több olyan sum(i-1) is lehet amire ez teljesül, 
    ezért egy mapot használok.
*/

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    ll x;
    cin >> n >> x;
    
    ll solutions=0;
    
    ll sum=0;
    map<ll, ll> sums;
    sums[0] = 1;

    for (int i=0; i<n; ++i) {
        ll a;
        cin >> a;
        sum += a;
        if (sums.count(sum-x))
            solutions += sums[sum-x];

        ++sums[sum];
    }

    cout << solutions << '\n';

    return 0;
}
