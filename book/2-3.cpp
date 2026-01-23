#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

size_t binary_search(vector<int> xs, int e) {
    /*size_t a(0), b( xs.size()-1 ), mid;
    //cout << a << ' ' << b << '\n';

    while (a<=b) {
        mid = a + (b-a)/2;
        //cout << "while: " << a << ' ' << mid << ' ' << b
        //    << ", " << xs[mid] << "==" << e << '\n' ;

        if (xs[mid] == e)
            return mid;
        else if (xs[mid]<e)
            a = mid+1;
        else
            b = mid-1;
    }

    throw 1; */

    size_t k = 0;
    size_t n = xs.size();
    for (size_t b = n / 2; 1 <= b; b/=2) {
        while (k+b < n and xs[k+b] <= e) k += b;
    }

    if (xs[k] == e) return k;
    else throw runtime_error("Error: value not found!");
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    size_t i, s;
    vector<int> xs;

    const int k = 5;


    cin >> n;
    for(i=0; i<(size_t)n; ++i) {
        cin >> x;
        xs.push_back(x);
    }


    sort(xs.begin(), xs.end()); 
   
    s = binary_search(xs, k);


    for (auto x: xs) {
        cout << x << ' ';
    }
    cout << '\n';
    cout << k << " found at index " << (int)s << '\n';

    return 0;
}
