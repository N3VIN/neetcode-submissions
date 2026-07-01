#include <cstdint>

class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(stck.empty()){
            stck.push(0);
            min = val;
        }
        else{
            stck.push(val - min);
            min = std::min(val, min);
        }
    }

    void pop() {
        auto val = stck.top();
        stck.pop();
        min = static_cast<int>(val < 0 ? min - val : min);
    }
    
    int top() {
        auto val = stck.top();
        return static_cast<int>(val > 0 ? val + min : min);
    }
    
    int getMin() {
       return min; 
    }

private:
    std::stack<int64_t> stck;
    int min{0};
};
