#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

using vi = vector<int>;
using si = set<int>;

template<typename T>
void print(T v) {
    for(auto &x: v)
        cout << x << ' ';
    cout << '\n';
}

int main(void) {
    vector<int> v = {6, 5, 8, 3, 9};

    sort(v.begin(), v.end());
    print<vi>(v);
    reverse(v.begin(), v.end());
    print<vi>(v);
    random_shuffle(v.begin(), v.end());
    print<vi>(v);
    /* With ordinary array you can give pointers:
        sort(a, a+n);
        reverse(a, a+n);
        random_shuffle(a, a+n);
    */
    
    set<int> s = {1, 3, 5};
    //set<int>::iterator it = s.begin();
    auto it = s.begin(); 
    cout << *it << '\n';
    cout << *(s.rbegin()) << '\n';
    auto it_f = s.find(3); // returns an iterator to the element
    cout << *it_f << '\n';
    auto auto_it_f2 = s.find(6);
    if (auto_it_f2 == s.end())
        cout << "6 not found.\n";
    
    // iterators can be moved forward ++ and backward --
    cout << *s.lower_bound(3) << '\n'; // iterator to first element whose value is at least x=3
    cout << *s.upper_bound(3) << '\n'; // iterator to first element whose value is greater than x=3;
    // if no such value is found, then the iterator is s.end()
    


    return 0;
}
