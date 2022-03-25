class MyQueue {
public:
    stack<int> n;
    MyQueue() {}
    
    void push(int x) {
        stack<int> tmp;
        while (!n.empty())
        {
            tmp.push(n.top());
            n.pop();
        }
        tmp.push(x);
        while(!tmp.empty())
        {
            n.push(tmp.top());
            tmp.pop();
        }
    }
    
    int pop(){
        int a = n.top();
        n.pop();
        return a;
    }
    
    int peek() {
        return n.top();
    }
    
    bool empty() {
    return n.empty();
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