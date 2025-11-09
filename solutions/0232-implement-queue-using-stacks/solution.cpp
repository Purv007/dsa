class MyQueue {
public:
stack<int>a;
stack<int>b;
    MyQueue() {
        
    }
    
    void push(int x) {
        a.push(x);
    }
    
    int pop() {
        int t;
        while(!a.empty()){
            t=a.top();
            a.pop();
            if(!a.empty()){
                b.push(t);
            }
        }

        int x;
        while(!b.empty()){
            x=b.top();
            b.pop();
            a.push(x);
        }
        return t;
    }
    
    int peek() {
        int t;
        while(!a.empty()){
            t=a.top();
            a.pop();
            b.push(t);
        }

        int x;
        while(!b.empty()){
            x=b.top();
            b.pop();
            a.push(x);
        }
        return t;
    }
    
    bool empty() {
        return a.empty();
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
