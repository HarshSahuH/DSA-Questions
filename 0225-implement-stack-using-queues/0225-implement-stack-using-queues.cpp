class MyStack {
public:
    queue<int> q1;
    
    
    MyStack() {
        
    }
    
    void push(int x) {
     q1.push(x);
     for(int i=0; i<q1.size()-1; i++)
     {
         q1.push(q1.front());
         q1.pop();
     }
    }
    
    int pop() {
        if(q1.size() == 0) return -1;
        
        int poped = q1.front();
        q1.pop();
        return poped;
    }
    
    int top() {
        if(q1.empty()) return -1;
        return q1.front();
    }
    
    bool empty() {
        if(q1.empty())
            return true;
        else
            return false;
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