#include <cmath>
#include <iomanip>
#include <iostream>
#include <queue>

void addNumber(
    int number, std::priority_queue<int>& lowers,
    std::priority_queue<int, std::vector<int>, std::greater<int> >& highers) {
    if (lowers.empty() || number < lowers.top()) {
        lowers.push(number);
    } else {
        highers.push(number);
    }
}

void rebalance(
    std::priority_queue<int>& lowers,
    std::priority_queue<int, std::vector<int>, std::greater<int> >& highers) {
    if (std::fabs(lowers.size() - highers.size()) <= 1) {
        return;
    } else if (lowers.size() > highers.size()) {
        highers.push(lowers.top());
        lowers.pop();
    } else {
        lowers.push(highers.top());
        highers.pop();
    }
}

double findMedian(
    std::priority_queue<int>& lowers,
    std::priority_queue<int, std::vector<int>, std::greater<int> >& highers) {
    if (lowers.size() == highers.size()) {
        return (double)(lowers.top() + highers.top()) / 2.0;
    } else if (lowers.size() > highers.size()) {
        return (double)lowers.top();
    } else {
        return (double)highers.top();
    }
}

int main() {
    std::priority_queue<int, std::vector<int>, std::greater<int> >
        highers;                      // min heap
    std::priority_queue<int> lowers;  // max heap

    int n;
    std::cin >> n;
    int number;
    for (int i = 0; i < n; ++i) {
        std::cin >> number;
        addNumber(number, lowers, highers);
        rebalance(lowers, highers);
        std::cout << std::fixed << std::setprecision(1)
                  << findMedian(lowers, highers) << std::endl;
    }
    return 0;
}
