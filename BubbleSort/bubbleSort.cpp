#include <iostream>
#include <vector>

// Returns the number of swaps needed to sort the array
template <typename T>
int bubbleSort(std::vector<T>& elements) {
    int size = elements.size();
    int numSwaps = 0;
    bool swapHappened;
    for (int i = 0; i < size; ++i) {
        swapHappened = false;
        // Iterate through vector and swap if need be
        for (int j = 0; j < size - 1; ++j) {
            if (elements[j] > elements[j + 1]) {
                std::swap(elements[j], elements[j + 1]);
                numSwaps++;
                swapHappened = true;
            }
        }

        if (!swapHappened) {
            break;
        }
    }
    return numSwaps;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int a_i = 0; a_i < n; a_i++) {
        std::cin >> a[a_i];
    }

    std::cout << "Array is sorted in " << bubbleSort(a) << " swaps."
              << std::endl;
    std::cout << "First Element: " << a[0] << std::endl;
    std::cout << "Last Element: " << a[a.size() - 1] << std::endl;
    return 0;
}
