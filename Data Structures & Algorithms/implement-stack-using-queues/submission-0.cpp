class MyStack {
private:
    std::queue<int> myStack;
public:
    MyStack() {
    }
    
    void push(int x) {
        myStack.push(x);
        for(int i = 0; i < myStack.size() - 1; i++){
            int temp = myStack.front();
            myStack.pop();
            myStack.push(temp);
        }
    }
    
    int pop() {
        int item = myStack.front();
        myStack.pop();
        return item;
    }
    
    int top() {
        return myStack.front();
    }
    
    bool empty() {
        return myStack.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */