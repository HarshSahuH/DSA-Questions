class MinStack {
public:
    stack<int> s;
    stack<int> supportingS;
    MinStack() {
        
    }
    
    void push(int val) {
       s.push(val); 
       if(supportingS.size() == 0 || val <= supportingS.top())
           supportingS.push(val);
    }
    
    void pop() {
        if(s.top() == supportingS.top())
        {
            supportingS.pop();
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        if(supportingS.size() ==0) return -1;
        return supportingS.top();
    }
};



/*
class MinStack {
private:
    stack<int> s1;
    stack<int> s2;
public:
    void push(int x) {
	    s1.push(x);
	    if (s2.empty() || x <= getMin())  s2.push(x);	    
    }
    void pop() {
	    if (s1.top() == getMin())  s2.pop();
	    s1.pop();
    }
    int top() {
	    return s1.top();
    }
    int getMin() {
	    return s2.top();
    }
};
*/

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */