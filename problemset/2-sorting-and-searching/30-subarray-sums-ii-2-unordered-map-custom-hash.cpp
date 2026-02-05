#include <iostream>
#include <unordered_map>
#include <chrono>
using ll = long long;
using namespace std;
constexpr size_t BUCKETS = 400'000;

/*
    Tudjuk, hogy ha i<j
        x=sum(i..j)=sum(j)-sum(i-1)
    ezt átrendezve:
        sum(i-1)=sum(j)-x
    Tehát ha valamilyen sum(j)-re létezik egy olyan sum(i-1) hogy ez teljesül,
    akkor az egy megoldás. Mivel több olyan sum(i-1) is lehet amire ez teljesül, 
    ezért egy mapot használok.

    UNORDERED_MAP VERZIÓ:
    Mivel a sima unordered_map-pal nem működik,
    valószínűleg mivel direkt vannak anti-hash tesztesetek,
    ezért egy saját hash függvény kell.
*/

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    ll x;
    cin >> n >> x;
    
    ll solutions=0;
    
    ll sum=0;
    unordered_map<ll, ll, custom_hash> sums(BUCKETS);
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
