#include <iostream>

using std::cin;
using std::cout;

int fibonacciHelper(int n, int currentNum, int nextNum) {
    if (n == 0)
        return currentNum;
    if (n == 1)
        return nextNum;
    return fibonacciHelper(n - 1, nextNum, currentNum + nextNum);
}

int fibonacci(int n) {
    // Complete the function.
    return fibonacciHelper(n, 0, 1);
}

int main() {
    int n;
    cin >> n;
    cout << fibonacci(n);
    return 0;
}
