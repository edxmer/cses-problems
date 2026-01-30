#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

struct Customer {
    int i;
    int time;
    bool is_arrival;
    Customer(int _i,int _time, bool _is_arrival): i(_i), time(_time), is_arrival(_is_arrival) {}
};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, a, b;
    cin >> n;
    vector<Customer> customers;
    customers.reserve(2*n);
    int max_room_count = 0;
    set<int> rooms_available;
    vector<int> chosen_rooms(n);

    for (int i=0; i<n; ++i) {
        cin >> a >> b;
        customers.emplace_back(i, a, true);
        customers.emplace_back(i, b, false);
    }

    sort(customers.begin(), customers.end(), [](auto &x, auto &y) {
        if (x.time == y.time) {
            return y.is_arrival < x.is_arrival;
        }
        return x.time < y.time;
    });


    for (int i = 0; i<2*n; ++i) {
        Customer c = customers[i];
        if (c.is_arrival) {
            if (rooms_available.size()) {
                chosen_rooms[c.i] = *rooms_available.begin();
                rooms_available.erase(rooms_available.begin());
            }
            else {
                ++max_room_count;
                chosen_rooms[c.i] = max_room_count;
            }
        }
        else {
            rooms_available.insert(chosen_rooms[c.i]);
        }
    }


    cout << max_room_count << '\n';
    for (int i=0; i<n; ++i) {
        cout << chosen_rooms[i] << ' ';
    }
    cout << '\n';

    return 0;
}
