#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> items;
vector<int> subset;

void generate(int i) {
    if (i==n) {
        for (auto &x: subset)
            cout << x << ' ';
        cout << '\n';
    } else {
        subset.push_back(items[i]);
        generate(i+1);
        subset.pop_back();
        generate(i+1);
    }
}

int main(void) {
    int i;
    cin >> n;
    items = vector<int>(n);

    for (i=0; i<n; ++i)
        cin >> items[i];
    
    generate(0);
}
