#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int f(int x) {
    const int dx = 412;

    return -1 * (x-dx) * (x-dx);
}

int main(void) {

    const int z = 2048;

    int k = -1;

    for (int b = z; b>=1; b/=2) {
        while (f(k+b) < f(k+b+1)) k+=b;
    }

    k+=1;

    printf("k: %d\n", k);


    return 0;
}
