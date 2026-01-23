#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, i, x, rounds, a, b, av, bv, tmp;
    cin >> n >> m;

    // indexing from 1..n
    vector<int> nums(n+1); // ind to number
    // 0 4 1 2 5 3
    vector<int> inds(n+1); // number to ind
    // 0 3 2 5 1 4

    for (i=1; i<=n; ++i) {
        cin >> x;
        nums[i] = x;
        inds[x] = i;
    }

    auto round_diff = [&](int k) {
        return (int)(k <= n && inds[k] < inds[k-1]); 
    };

    rounds = 1;

    for (i=1;i<n;++i)
        if (inds[i+1]<inds[i])
            ++rounds;

    while(m--) {
        cin >> a >> b;

        if (a != b) {
            //swap a, and b and change rounds based on that
            // remove previous round calculation
            av = nums[a];
            bv = nums[b];

            // make av the smaller one
            if (bv < av) {
                tmp = av;
                av = bv;
                bv = tmp;
            }


            if (bv-av == 1) { // they are next to each other
                rounds -= round_diff(av) + round_diff(bv) +
                          round_diff(bv+1);
            }
            else {
                rounds -= round_diff(av) + round_diff(av+1) +
                          round_diff(bv) + round_diff(bv+1);
            }

            // swap
            swap(nums[a], nums[b]);
            swap(inds[av], inds[bv]);
            
            // add new round calculations
            if (bv-av == 1) { // they are next to each other
                rounds += round_diff(av) + round_diff(bv) +
                          round_diff(bv+1);
            }
            else {
                rounds += round_diff(av) + round_diff(av+1) +
                          round_diff(bv) + round_diff(bv+1);
            }
        }
        
        cout << rounds << '\n';
    }


    return 0;
}
