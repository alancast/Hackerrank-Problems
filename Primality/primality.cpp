#include <iostream>

using std::cin;
using std::cout;
using std::endl;

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (long i = 2; (i * i) <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int p;
    cin >> p;
    for (int a0 = 0; a0 < p; a0++) {
        int n;
        cin >> n;
        if (isPrime(n)) {
            cout << "Prime" << endl;
        } else {
            cout << "Not prime" << endl;
        }
    }
    return 0;
}