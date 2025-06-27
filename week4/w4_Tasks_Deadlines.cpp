#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n, a, d;
    cin >> n;

    vector<pair<int, int>> tasks;

    for (int i = 0; i < n; i++) {
        cin >> a >> d;
        tasks.push_back({a, d});
    }

    sort(tasks.begin(), tasks.end());

    long long time = 0;
    long long reward = 0;

    for (auto& task : tasks) {
        int duration = task.first;
        int deadline = task.second;
        time += duration;
        reward += (deadline - time);
    }

    cout << reward << endl;

    return 0;
}
