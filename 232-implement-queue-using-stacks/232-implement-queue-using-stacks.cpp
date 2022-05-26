class MyQueue {
public:
    stack <int> input , output;
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        if(output.empty()){
            while(!input.empty()){
            int tp = input.top();
            input.pop();
            output.push(tp);
            }
        }
        int elem = output.top();
        output.pop();
        return elem;
    }
    
    int peek() {
        
        if(output.empty()){
            while(!input.empty()){
            int tp = input.top();
            input.pop();
            output.push(tp);
            }
        }
        int elem = output.top();
        return elem;
        
    }
    
    bool empty() {
        if(input.empty() && output.empty()) return true;
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