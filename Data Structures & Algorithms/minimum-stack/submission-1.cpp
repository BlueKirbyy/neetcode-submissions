class MinStack {
private:
    std::stack<int> values;
    std::stack<int> minStack;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        values.push(val);
        if(minStack.empty()){
            minStack.push(val);
        }
        else{
            minStack.push(min(val, minStack.top()));
        }        
    }
    
    void pop() {
        values.pop();
        minStack.pop();
    }
    
    int top() {
        return values.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
