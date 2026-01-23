#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <deque>
#include <stack>
#include <queue>

using namespace std;

int main(void) {
    
    // VECTOR
    vector<int> v1(4); // len 4, starting value 0
    vector<int> v2(5, 2); // len 5, starting value 2
    v2.push_back(5);
    cout << v2.back() << '\n';
    v2.pop_back(); // no return value
    cout << v2.back() << '\n';
    for (auto x: v2) cout << x << ' ';
    cout << "\n\n";

    // STRING
    string str1 = "hello";
    string str2 = str1 + str1;
    str2[5] = 'm';
    cout << str2 << '\n'; 
    string str3 = str2.substr(5, 5); // start from index 2, 3 length
    cout << str3 << "\n\n";

    // SET
    set<int> s1 = {1, 2, 3, 4}; //O(log(n)); also unordered_set for avg O(1) hash table
    s1.insert(5);
    s1.erase(4);
    cout << "set: 3 count: " << s1.count(3) << ", 4 count: " << s1.count(4) << "\n\n";
    
    // MULTISET
    multiset<int> s2;
    s2.insert(5);
    s2.insert(5);
    s2.insert(5);
    s2.insert(5);
    cout << "multiset: 5 count: " << s2.count(5) << ", 5 count after erase: ";
    s2.erase(5);
    cout << s2.count(5) << '\n';
    s2.insert(5);
    s2.insert(5);
    // if i only want to remove 1:
    s2.erase(s2.find(5));
    cout << s2.count(5) << "\n\n";


    // MAP
    map<string, int> m;
    m["cat"] = 1;
    m["tiramisu"] = 2;
    m["banana"] = 3;
    cout << m["banana"] << '\n';
    cout << m["nothing"] << '\n'; 
    // if you request a key that is not in it, it is created with its default value
    cout << m.count("tiramisu") << '\n';
    // count checks if the key exists
    // Iterate through all pairs of values:
    for (auto &x: m) {
        cout << x.first << ' ' << x.second << '\n';
    }


    // BITSET
    bitset<32> b, c;
    
    b[10] = 1;
    c[15] = 1;
    b[15] = 1;

    cout << (b&c) << '\n';
    cout << (b|c) << '\n';
    cout << (b^c) << '\n';
    cout << b.count() << ' ' << c.count() << "\n\n";


    // DEQUE
    
    deque<int> dq;
    dq.push_back(0);
    dq.push_back(1);
    dq.push_front(2);
    cout << dq.front() << ' ' << dq.back() << '\n';
    dq.pop_back();
    dq.pop_front();
    
    
    //STACK
    stack<int> st;
    st.push(3);
    st.push(2);
    st.push(5);
    cout << st.top() << '\n'; // 5
    st.pop();
    cout << st.top() <<'\n'; // 2

    // QUEUE
    queue<int> q;
    q.push(3);
    q.push(2);
    q.push(5);
    cout << '\n' << q.front() << '\n'; // 3
    q.pop();
    cout << q.front() << "\n\n"; // 2

    // PRIORITY_QUEUE

    priority_queue<int> pq;
    pq.push(3);
    pq.push(5);
    pq.push(7);
    pq.push(2);
    cout << pq.top() << "\n"; // 7
    pq.pop();
    cout << pq.top() << "\n"; // 5
    pq.pop();
    pq.push(6);
    cout << pq.top() << "\n"; // 6
    pq.pop();

    // priority queue for removing the smallest elements:
    // priority_queue<int,vector<int>,greater<int>> q;


    return 0;
}
