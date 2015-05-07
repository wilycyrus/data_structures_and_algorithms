#include <queue>
#include <iostream>
// #include <algorithm>

using namespace std;

class RunningMedian {
public:
    void Insert(int x);
    float Median();
    void PrintLow();
private:
    priority_queue<int> low_;
    priority_queue<int, vector<int>, greater<int>> high_;
};

void RunningMedian::Insert(int x) {
    if (low_.size() == high_.size()) {
        if (!low_.empty() && x > low_.top()) {
            high_.push(x);
            int to_low = high_.top();
            high_.pop();
            low_.push(to_low);
        } else {
            low_.push(x);
        }
    } else {
        low_.push(x);
        int to_high = low_.top();
        low_.pop();
        high_.push(to_high);
    }
}

float RunningMedian::Median() {
    if (low_.size() == high_.size()) {
        return 0.5*(low_.top() + high_.top());
    } else {
        return low_.top();
    }
}

int main() {
    int numbers[] = {2, 9, 3, 5, 7, 1, 6, 4, 8};
    RunningMedian median;
    for (auto number: numbers) {
        median.Insert(number);
        cout << median.Median() << endl;
    }
    return 0;
}