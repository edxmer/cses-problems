#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &xs, int left, int mid, int right) {
    size_t i, l, r;
    vector<int> L(mid-left+1), R(right-(mid+1)+1);

    for (i=0; i<L.size(); ++i)
        L[i] = xs[left+i];
    
    for (i=0; i<R.size(); ++i)
        R[i] = xs[mid + 1 + i];
    
    l = 0;
    r = 0;

    for (i=left; i<=(size_t)right; ++i) {
        if (L.size() <= l)
            xs[i] = R[r++];
        else if (R.size() <= r)
            xs[i] = L[l++];
        else if (L[l] < R[r])
            xs[i] = L[l++];
        else
            xs[i] = R[r++];
    }

}

void merge_sort(vector<int> &xs, int left, int right) {

    if (left == right)
        return;

    int mid = left + (right - left) / 2;
    merge_sort(xs, left, mid);
    merge_sort(xs, mid+1, right);
    merge(xs, left, mid, right);

}



int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    size_t i;
    vector<int> xs;


    cin >> n;
    for(i=0; i<(size_t)n; ++i) {
        cin >> x;
        xs.push_back(x);
    }



    merge_sort(xs, 0, n-1);



    for (auto x: xs) {
        cout << x << ' ';
    }
    cout << '\n';


    return 0;
}
