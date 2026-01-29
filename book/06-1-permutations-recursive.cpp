#include <iostream>
#include <vector>

using namespace std;

vector<int> values;
vector<int> permutation;
vector<bool> chosen;
int n;

void search() {
    if ((int)permutation.size() == n) {
        for (auto &x: permutation)
            cout << x << ' ';
        cout << '\n';
    } else {
        int i;
        for (i=0; i<n; ++i) {
            if (!chosen[i]) {
                chosen[i] = true;
                permutation.push_back(values[i]);
                search();
                chosen[i] = false;
                permutation.pop_back();

            }
        }
    }
}

int main(void) {
    int i;
    cin >> n;
    values = vector<int>(n);
    permutation.reserve(n);
    chosen = vector<bool>(n, false);

    for (i=0; i<n; ++i)
        cin >> values[i];

    search();


    return 0;
}
