#include <iostream>
#include <algorithm>
using namespace std;

int greedy_steps(int n) {
    int steps = 0;
    while (n > 0) {
        int max_digit = 0;
        int x = n;
        while (x > 0) {
            max_digit = max(max_digit, x % 10);
            x /= 10;
        }
        n -= max_digit;
        steps++;
    }
    return steps;
}

int main() {
    int n;
    cin >> n;
    cout << greedy_steps(n) << endl;
    return 0;
}
