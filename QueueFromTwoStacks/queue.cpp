#include <iostream>
#include <stack>

class MyQueue {
   public:
    std::stack<int> stack_newest_on_top, stack_oldest_on_top;
    void push(int x) { stack_newest_on_top.push(x); }

    void pop() {
        if (stack_oldest_on_top.empty()) {
            reverse();
        }

        if (!stack_oldest_on_top.empty()) {
            stack_oldest_on_top.pop();
        }
    }

    int front() {
        if (stack_oldest_on_top.empty()) {
            reverse();
        }
        return stack_oldest_on_top.top();
    }

   private:
    void reverse() {
        while (!stack_newest_on_top.empty()) {
            stack_oldest_on_top.push(stack_newest_on_top.top());
            stack_newest_on_top.pop();
        }
    }
};

int main() {
    MyQueue q1;
    int q, type, x;
    std::cin >> q;

    for (int i = 0; i < q; i++) {
        std::cin >> type;
        if (type == 1) {
            std::cin >> x;
            q1.push(x);
        } else if (type == 2) {
            q1.pop();
        } else
            std::cout << q1.front() << std::endl;
    }
    return 0;
}
