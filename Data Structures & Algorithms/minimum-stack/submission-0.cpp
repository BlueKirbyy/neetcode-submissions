class MinStack {
public:
    //keep track of 2 vectors. 1 stack and 1 for the min stack.
    //push back val to stack. if minStack is empty, push val to minStack.
    //if minStack is not empty, compare val with the last value in minStack.
    //if it is lesser than, then push the val to minStack.
    //if it is greater than, then push the current min to minStack

    //for pop, make sure to pop from both vectors
    //for top, just return the last element of stack
    //for getmin, return the last element of minStack
    vector<int> stack;
    vector<int> minStack;

    MinStack() {
        
    }
    
    void push(int val) {
        stack.push_back(val);
        if(minStack.empty()){
            minStack.push_back(val);
        }
        else if(val < minStack[minStack.size() - 1]){
            minStack.push_back(val);
        }
        else{
            minStack.push_back(minStack[minStack.size() - 1]);
        }
    }
    
    void pop() {
        stack.pop_back();
        minStack.pop_back();

    }
    
    int top() {
        return stack[stack.size() - 1];
    }
    
    int getMin() {
        return minStack[minStack.size() - 1];
    }
};
