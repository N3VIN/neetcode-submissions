class MinStack {
   public:
    MinStack() {}

    void push(int val) {
        // if(min)
        main.push(val);
        if (min.empty()) {
            min.push(val);
        }
        else{
            min.push(std::min(val, min.top()));
        }
    }

    void pop() {
        main.pop();
        min.pop();
    }

    int top() { return main.top(); }

    int getMin() { return min.top(); }

   private:
    std::stack<int> main;
    std::stack<int> min;
};
