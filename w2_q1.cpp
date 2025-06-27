#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> songs(n);
    for (int i = 0; i < n; ++i) {
        cin >> songs[i];
    }

    set<int> seen;
    int left = 0, right = 0, max_len = 0;

    while (right < n) {
        if (!seen.count(songs[right])) {
            seen.insert(songs[right]);
            max_len = max(max_len, right - left + 1);
            right++;
        } else {
            seen.erase(songs[left]);
            left++;
        }
    }

    cout << max_len << endl;
    return 0;
}
