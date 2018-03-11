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

int number_needed(string a, string b) {
    // Initialize shared count vector
    vector<int> counts(26);
    fill(counts.begin(), counts.end(), 0);

    // Count number of each character in string 1
    for (auto c : a) {
        counts[c - 'a']++;
    }

    // Subtract number of each character in string 2
    for (auto c : b) {
        counts[c - 'a']--;
    }

    // Find total difference between characters
    int difference = 0;
    for (auto count : counts) {
        difference += abs(count);
    }
    return difference;
}

int main() {
    string a;
    cin >> a;
    string b;
    cin >> b;
    cout << number_needed(a, b) << endl;
    return 0;
}
