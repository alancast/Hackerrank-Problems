#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

int lonely_integer(std::vector<int> a) {
    int value = 0;
    // any number XOR'd with itself is 0
    // any number XOR'd with 0 is itself
    // So all the pairs cancel out, leaving us with just the value
    for (auto i : a) {
        value ^= i;
    }
    return value;
}

int main() {
    int n;
    cin >> n;
    std::vector<int> a(n);
    for (int a_i = 0; a_i < n; a_i++) {
        cin >> a[a_i];
    }
    cout << lonely_integer(a) << endl;
    return 0;
}
