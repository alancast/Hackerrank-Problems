#include <iostream>
#include <stack>

bool is_opening(char brace) {
    return brace == '{' || brace == '[' || brace == '(';
}

bool is_closing(char brace) {
    return brace == '}' || brace == ']' || brace == ')';
}

bool braces_match(char opening, char closing) {
    if ((opening == '{' && closing == '}') ||
        (opening == '[' && closing == ']') ||
        (opening == '(' && closing == ')')) {
        return true;
    }
    return false;
}

bool is_balanced(std::string expression) {
    // Initialize deques from string
    std::stack<char> openings;
    for (auto c : expression) {
        if (is_opening(c)) {
            openings.push(c);
        } else {
            if (openings.empty() || !braces_match(openings.top(), c)) {
                return false;
            }
            openings.pop();
        }
    }

    if (!openings.empty()) {
        return false;
    }

    return true;
}

int main() {
    int t;
    std::cin >> t;
    for (int a0 = 0; a0 < t; a0++) {
        std::string expression;
        std::cin >> expression;
        bool answer = is_balanced(expression);
        if (answer)
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    }
    return 0;
}
