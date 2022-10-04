class MyQueue {
public:
    stack<int>io;
    stack<int>op;
    MyQueue() {
        
    }
    
    void push(int x) {
        io.push(x);
    }
    
    int pop() {
        if(op.empty()){
            while(!io.empty()){
                op.push(io.top());
                io.pop();
            }
        }
        
        int ans = op.top();
        op.pop();
        return ans;
    }
    
    int peek() {
        if(op.empty()){
            while(!io.empty()){
                op.push(io.top());
                io.pop();
            }
        }
        return op.top();
    }
    
    bool empty() {
        if(io.empty())return op.empty();
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */