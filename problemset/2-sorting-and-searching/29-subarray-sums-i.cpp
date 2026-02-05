#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, x;
    cin >> n >> x;
    
    int count=0;
    int sum=0;

    vector<int> v;
    v.reserve(n);
    int tail = 0;

    for (int i=0; i<n; ++i) {
        int a;
        cin >> a;

        v.push_back(a);

        sum += a;

        while (x < sum) {
            sum -= v[tail];
            ++tail;
        }
        
        if (sum == x)
            ++count;
    }

    cout << count << '\n';


    return 0;
}
