#include <iostream>
#include <vector>


using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    size_t i, j;
    vector<int> xs;


    cin >> n;
    for(i=0; i<(size_t)n; ++i) {
        cin >> x;
        xs.push_back(x);
    }



    for (i=0;i<xs.size(); ++i) {
        for (j=i+1; j<xs.size(); ++j) {
            if (xs[i]>xs[j])
                swap(xs[i], xs[j]);
        }
    }

    for (auto x: xs) {
        cout << x << ' ';
    }
    cout << '\n';


    return 0;
}
