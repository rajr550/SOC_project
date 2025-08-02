#include <iostream>
#include <stack>
#include <set>

using namespace std;

class MedianStack {
private:
    stack<int> s;
    multiset<int> sorted;
    multiset<int>::iterator mid;

public:
    void push(int x) {
        s.push(x);
        if (sorted.empty()) {
            sorted.insert(x);
            mid = sorted.begin();
        } else {
            sorted.insert(x);
            if (x < *mid) {
                if (sorted.size() % 2 == 0) --mid;
            } else {
                if (sorted.size() % 2 != 0) ++mid;
            }
        }
    }

    void pop() {
        if (s.empty()) return;

        int x = s.top();
        s.pop();

        if (x == *mid) {
            auto it = mid;
            if (sorted.size() % 2 == 1) ++mid;
            else --mid;
            sorted.erase(it);
        } else {
            if (x < *mid) {
                if (sorted.size() % 2 == 0) ++mid;
                sorted.erase(sorted.lower_bound(x));
            } else {
                if (sorted.size() % 2 == 1) --mid;
                sorted.erase(sorted.lower_bound(x));
            }
        }

        if (sorted.empty()) mid = sorted.end();
    }

    int top() {
        return s.empty() ? -1 : s.top();
    }

    double getMedian() {
        if (sorted.empty()) return -1;

        if (sorted.size() % 2 == 1) return *mid;

        auto next = next(mid);
        return (*mid + *next) / 2.0;
    }

    bool empty() {
        return s.empty();
    }
};

int main() {
    MedianStack ms;

    ms.push(5);
    ms.push(2);
    ms.push(10);
    ms.push(4);
    
    cout << "Median: " << ms.getMedian() << endl; // Should be 4.5
    ms.pop();
    cout << "Top: " << ms.top() << endl;          // Should be 10
    cout << "Median: " << ms.getMedian() << endl; // Should be 5

    ms.pop();
    cout << "Median: " << ms.getMedian() << endl; // Should be 3.5

    return 0;
}
