#include <iostream>
#include <vector>
using namespace std;

int currsum = 0;

void findsums(vector<int> &sums, int *nums, int n) {
    if (n == 0) {
        sums.push_back(currsum);
    } else {
        currsum += *nums;
        findsums(sums, nums+1, n-1);
        currsum -= *nums;
        findsums(sums, nums+1, n-1);
    }
    return;
}

int main(void) {

    int nums[] = {1, 2, 4, 6, 8, 9, 13, 15, 23};
    int n = sizeof(nums)/sizeof(*nums);
    int x = 12;

    int n1 = n/2;
    int n2 = n-n1;

    vector<int> sumsA, sumsB;

    findsums(sumsA, nums, n1);
    findsums(sumsB, nums+n1, n2);

    for (int i=0; i<sumsA.size(); ++i) for (int j=0; j<sumsB.size(); ++j) if (sumsA[i]+sumsB[j] == x) {
        cout << "POSSIBLE\n";
        return 0;
    }

    cout << "NOT POSSIBLE\n";


    return 0;
}
