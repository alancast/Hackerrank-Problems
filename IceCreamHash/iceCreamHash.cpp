#include <iostream>
#include <unordered_map>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

void printAnswer(int flav1, int flav2) {
    if (flav1 > flav2) {
        cout << flav2 << " " << flav1 << endl;
    } else {
        cout << flav1 << " " << flav2 << endl;
    }
}

void solve(std::vector<int> arr, int money) {
    // Populate map of costs and how many flavors are that cost
    std::unordered_map<int, std::vector<int>> costs;
    for (int i = 0; i < arr.size(); ++i) {
        auto cost = arr[i];
        if (costs.find(cost) != costs.end()) {
            costs[cost].push_back(i + 1);
        } else {
            std::vector<int> v;
            v.push_back(i + 1);
            costs[cost] = v;
        }
    }

    // If the amount needed is also in the map of costs
    // and there is one flavor of price cost and another of price needed
    // then we have our two flavors
    int needed;
    for (std::unordered_map<int, std::vector<int>>::iterator it = costs.begin();
         it != costs.end(); ++it) {
        needed = money - it->first;

        // Needed amount is the same as what this cost
        if (it->first == needed) {
            // If there are multiple flavors at this cost we are set
            if (it->second.size() > 1) {
                printAnswer(it->second[0], it->second[1]);
                return;
            }
        } else if (costs.find(needed) != costs.end()) {
            printAnswer(it->second[0], costs[needed][0]);
            return;
        }
    }
}

int main() {
    int t;
    cin >> t;
    for (int a0 = 0; a0 < t; a0++) {
        int money;
        cin >> money;
        int n;
        cin >> n;
        std::vector<int> arr(n);
        for (int arr_i = 0; arr_i < n; arr_i++) {
            cin >> arr[arr_i];
        }
        solve(arr, money);
    }
    return 0;
}
