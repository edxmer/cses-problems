#include <iostream>
#include <vector>

using namespace std;

#define ZERO false
#define ONE true

class Bits {
    vector<bool> bits;

    public:
        Bits(int n) : bits(n, ZERO) {}
    
        void turn(int i) {
            bits[i] = !bits[i];
        }

        void print() {
            for (const auto &b: bits) {
            if (b)
                cout << 1;
            else
                cout << 0;
            }
            cout << '\n';
        }

        void solve(int layer) {
            if (layer == 0) {
                print();
                turn(0);
                print();
            } else {
                solve(layer-1);
                turn(layer);
                solve(layer-1);
            }
        }
};


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    Bits bits(n);

    bits.solve(n-1);

    return 0;
}
