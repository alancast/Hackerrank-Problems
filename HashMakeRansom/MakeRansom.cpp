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

void populate_map(vector<string>& input, map<string, int>& out_map) {
    for (auto word : input) {
        if (out_map.find(word) == out_map.end()) {
            out_map[word] = 1;
        } else {
            out_map[word]++;
        }
    }
}

bool ransom_note(vector<string> magazine, vector<string> ransom) {
    if (ransom.size() > magazine.size()) {
        return false;
    }

    // Populate hashmap of magazine words
    map<string, int> magazine_map;
    populate_map(magazine, magazine_map);

    // Make sure every entry of ransom is in magazine
    for (auto word : ransom) {
        if (magazine_map.find(word) == magazine_map.end() ||
            magazine_map[word] == 0) {
            return false;
        } else {
            magazine_map[word]--;
        }
    }
    return true;
}

int main() {
    int m;
    int n;
    cin >> m >> n;
    vector<string> magazine(m);
    for (int magazine_i = 0; magazine_i < m; magazine_i++) {
        cin >> magazine[magazine_i];
    }
    vector<string> ransom(n);
    for (int ransom_i = 0; ransom_i < n; ransom_i++) {
        cin >> ransom[ransom_i];
    }
    if (ransom_note(magazine, ransom))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}
