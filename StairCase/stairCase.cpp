#include <iostream>
#include <unordered_map>

using std::cin;
using std::cout;
using std::endl;

int stairCaseOptions(int n) {
    // Validate input
    if (n <= 0) {
        return 0;
    }
    // Base conditions
    if (n == 1) {
        return 1;
    } else if (n == 2) {
        return 2;
    } else if (n == 3) {
        return 4;
    }

    return stairCaseOptions(n - 1) + stairCaseOptions(n - 2) + stairCaseOptions(n - 3);
}

int dpStairCaseOptions(int n, std::unordered_map<int, int>& possibilities) {
    if (n < 0)
        return 0;

    if (n == 0)
        return 1;

    if (possibilities.find(n) == possibilities.end()) {
        int count = dpStairCaseOptions(n - 1, possibilities) +
                    dpStairCaseOptions(n - 2, possibilities) +
                    dpStairCaseOptions(n - 3, possibilities);
        possibilities[n] = count;
    }
    return possibilities[n];
}

int main() {
    int s;
    cin >> s;
    std::unordered_map<int, int> possibilities;
    for (int a0 = 0; a0 < s; a0++) {
        int n;
        cin >> n;
        cout << dpStairCaseOptions(n, possibilities) << endl;
    }
    return 0;
}
