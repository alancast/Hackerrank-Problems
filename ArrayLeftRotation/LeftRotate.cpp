#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// Best solution O(n) in time, O(1) in space
int GreatestCommonDenominator(int a, int b) {
    return b == 0 ? a : GreatestCommonDenominator(b, a % b);
}

vector<int> array_left_rotation(vector<int> a, int n, int k) {
    // Bad input or no rotation needed
    if (a.empty() || n == 0 || k == 0 || n == k) {
        return a;
    }

    int swap, move1, move2;
    for (int i = 0; i < GreatestCommonDenominator(n, k); ++i) {
        swap = a[i];
        move1 = i;
        while (1) {
            move2 = move1 + k;
            if (move2 >= n) {
                move2 = move2 - n;
            }
            if (move2 == i) {
                a[move1] = swap;
                break;
            }
            a[move1] = a[move2];
            move1 = move2;
        }
    }

    return a;
}

// O(n) in time and space
/*
vector<int> array_left_rotation(vector<int> a, int n, int k) {
    // Bad input or no rotation needed
    if (a.empty() || n == 0 || k == 0 || n == k) {
        return a;
    }

    vector<int> rotated;
    for (int i = 0; i < a.size(); ++i) {
        rotated.push_back(a[(i + k) % n]);
    }

    return rotated;
}
*/

int main() {
    int n;
    int k;
    cin >> n >> k;
    vector<int> a(n);
    for (int a_i = 0; a_i < n; a_i++) {
        cin >> a[a_i];
    }
    vector<int> output = array_left_rotation(a, n, k);
    for (int i = 0; i < n; i++) {
        cout << output[i] << " ";
    }
    cout << endl;
    return 0;
}
