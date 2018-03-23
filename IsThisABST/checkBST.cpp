#include <climits>
#include <set>
#include <vector>

// The Node struct is defined as follows:
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Method 2: In order tree traversal
// if all items are larger than last one it's good
void inOrder(Node* root, std::vector<int>& values) {
    // Base condition
    if (!root) {
        return;
    }

    inOrder(root->left, values);
    values.push_back(root->data);
    inOrder(root->right, values);
}

// Method 1: recursive solution
bool checkBSTHelper(Node* root, int lower_bound, int upper_bound,
                    std::set<int>& values) {
    // End condition
    if (!root) {
        return true;
    }

    int data = root->data;
    // Make sure data isn't more or less than a parent
    if (data <= lower_bound || data >= upper_bound) {
        return false;
    }
    // Make sure value isn't somewhere in the tree
    if (values.find(data) != values.end()) {
        return false;
    }

    values.insert(data);

    // Left subtree you update the upper bound
    // Right subtree you update the lower bound
    return checkBSTHelper(root->left, lower_bound, root->data, values) &&
           checkBSTHelper(root->right, root->data, upper_bound, values);
}

bool checkBST(Node* root) {
    // We'll say nullptr root is a valid BST
    if (!root) {
        return true;
    }

    // Method 1:
    std::set<int> values;
    values.insert(root->data);

    return checkBSTHelper(root->left, INT_MIN, root->data, values) &&
           checkBSTHelper(root->right, root->data, INT_MAX, values);

    // Method 2:
    /*
    std::vector<int> values;
    inOrder(root, values);

    // Make sure all values are in order
    int last = INT_MIN;
    for (auto value : values) {
        if (value > last) {
            last = value;
        } else {
            return false;
        }
    }

    return true;
    */
}

int main() {}