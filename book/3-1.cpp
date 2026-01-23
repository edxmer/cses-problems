#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

bool ok(int x) {
    const int k = 2048;
    return x>=k;
}


int main(void) {
    
    const int z = 2048;

    int k = -1;

    for (int b = z; b>=1; b/=2)
        while (!ok(k+b)) k+=b;
    ++k;

    printf("k: %d\n", k);


    return 0;
}
