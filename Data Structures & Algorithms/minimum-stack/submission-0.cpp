#include <limits>

class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        int currentMin = stck.empty() ? val : std::min(val, minStck.top());
        stck.push(val);
        minStck.push(currentMin);
    }
    
    void pop() {
       stck.pop(); 
       minStck.pop();
    }
    
    int top() {
       return stck.top();
    }
    
    int getMin() {
        return minStck.top();
    }

private:
    std::stack<int> stck{};
    std::stack<int> minStck{};
};