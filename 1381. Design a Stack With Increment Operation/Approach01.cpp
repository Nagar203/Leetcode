#include <unordered_set>
#include <vector>

class CustomStack {
 public:
  CustomStack(int maxStackSize) : maxStackSize(maxStackSize) {}

  void push(int value) {
    if (stack.size() == maxStackSize)
      return;
    stack.push(value);
    pendingIncrements.push_back(0);
  }

  int pop() {
    if (stack.empty())
      return -1;
    const int stackIndex = stack.size() - 1;
    if (stackIndex > 0)
      pendingIncrements[stackIndex - 1] += pendingIncrements[stackIndex];
    const int returnValue = stack.top() + pendingIncrements[stackIndex];
    stack.pop();
    pendingIncrements.pop_back();
    return returnValue;
  }

  void increment(int count, int value) {
    if (stack.empty())
      return;
    const int lastIndex = min(count - 1, static_cast<int>(stack.size()) - 1);
    pendingIncrements[lastIndex] += value;
  }

 private:
  const int maxStackSize;
  stack<int> stack;
  vector<int> pendingIncrements;
};