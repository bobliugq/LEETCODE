class MinStack {
    stack<int> minStack;
    stack<int> stk;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        stk.push(x);
        if (!minStack.empty()) {
            if (minStack.top() < x) {
                minStack.push(minStack.top());
                return;
            }
        }
        minStack.push(x);
    }
    
    void pop() {
        if (!stk.empty()) {
            stk.pop();
            minStack.pop();
        }
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
