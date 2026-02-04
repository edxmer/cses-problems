#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

constexpr ll MAX_N = 200'000;

struct task {
      ll duration;
      ll deadline;
};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, i;
    cin >> n;

    vector<task> tasks(MAX_N);

    for (i=0; i<n; ++i) {
        cin >> tasks[i].duration >> tasks[i].deadline;
    }

    sort(tasks.begin(), tasks.begin()+n, [](auto &a, auto &b){
        if (a.duration == b.duration)
            return a.deadline < b.deadline;
        return a.duration < b.duration;
    });

    ll t = 0, score = 0;

    for (i=0; i<n; ++i) {
        t += tasks[i].duration;
        score += tasks[i].deadline - t;
    }

    cout << score << '\n';


    return 0;
}
