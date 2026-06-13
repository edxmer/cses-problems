#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main()
{
    // i/o optimisations
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k; // k=3
    cin >> n >> k;

    vector<ll> v(n);
    ll max = 0;
    ll sum = 0;

    for (ll &x : v)
    {
        cin >> x;

        if (max < x) max = x;
        sum += x;
    }

    // test_max_sum(m) is a monotically increasing function,
    // so we can use a binary search to find the smallest m to 
    // which it returns true

    auto test_max_sum = [&](ll m)
    {
        // Return false if m is too small
        // Return true if m is large enough

        ll local_sum = 0;
        ll group_idx = 0;

        for (int i=0; i<n && group_idx < k; ++i)
        {
            local_sum += v[i];
            if (m < local_sum)
            {
                local_sum = v[i];
                group_idx += 1;
            }
        }

        if (k <= group_idx) { return false; }
        
        return true;
    };

    
    ll s = max-1;

    for (ll b=sum-max; 0<b; b/=2)
        while (!test_max_sum(s+b)) s += b;
    
    cout << s + 1 << '\n';

    return 0;
}
