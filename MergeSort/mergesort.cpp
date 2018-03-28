#include <iostream>
#include <sstream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

void print_array(vector<int>& arr) {
    for (auto num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

void merge(long left, long middle, long right, vector<int>& arr, long& swaps) {
    // Create temp arrays for left and right
    vector<int> left_arr(arr.begin() + left, arr.begin() + middle + 1);
    vector<int> right_arr(arr.begin() + middle + 1, arr.begin() + right + 1);

    long left_counter = 0;
    long right_counter = 0;
    long arr_index = left;

    // Merge the elements
    while (left_counter < left_arr.size() && right_counter < right_arr.size()) {
        if (left_arr[left_counter] <= right_arr[right_counter]) {
            arr[arr_index] = left_arr[left_counter];
            left_counter++;
        } else {
            arr[arr_index] = right_arr[right_counter];
            right_counter++;
            // How many things on the left side did this need to move infront of
            swaps = swaps + (left_arr.size() - left_counter);
        }
        arr_index++;
    }

    // Copy any leftovers
    while (left_counter < left_arr.size()) {
        arr[arr_index] = left_arr[left_counter];
        left_counter++;
        arr_index++;
    }

    while (right_counter < right_arr.size()) {
        arr[arr_index] = right_arr[right_counter];
        right_counter++;
        arr_index++;
    }
}

void mergeSort(long left, long right, vector<int>& arr, long& swaps) {
    if (left < right) {
        long middle = (left + right) / 2;
        mergeSort(left, middle, arr, swaps);
        mergeSort(middle + 1, right, arr, swaps);
        merge(left, middle, right, arr, swaps);
    }
}

long countInversions(vector<int>& arr) {
    long inversions = 0;
    mergeSort(0, arr.size() - 1, arr, inversions);
    return inversions;
}

int main() {
    int t;
    cin >> t;
    for (int a0 = 0; a0 < t; a0++) {
        int n;
        cin >> n;
        vector<int> arr;
        std::string numbers;
        std::getline(cin, numbers); // waste line
        std::getline(cin, numbers); // actually get the numbers
        std::istringstream is(numbers);
        while (is >> n) {
            arr.push_back(n);
        }
        long result = countInversions(arr);
        cout << result << endl;
    }
    return 0;
}
