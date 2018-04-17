#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

long long make_change(std::vector<int> coins, int money) {
    std::vector<long long> possibilities(money + 1);
    possibilities[0] = 1;

    for (auto coin : coins) {
        for (int i = coin; i < possibilities.size(); ++i) {
            possibilities[i] += possibilities[i - coin];
        }
    }

    return possibilities[money];
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    std::vector<int> coins(m);
    for (int coins_i = 0; coins_i < m; coins_i++) {
        cin >> coins[coins_i];
    }
    cout << make_change(coins, n) << endl;
    return 0;
}
