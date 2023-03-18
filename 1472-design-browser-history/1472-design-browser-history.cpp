class BrowserHistory {
    stack<string> f, b;
    string curr = "";
    
public:
    BrowserHistory(string homepage) {
        curr = homepage;
    }
    
    void visit(string url) {
        if (curr != "") b.push(curr);
        curr = url;
        
        while (!f.empty()) f.pop();
    }
    
    string back(int steps) {        
        while (steps-- && !b.empty())
        {
            f.push(curr);
            curr = b.top();
            b.pop();
        }
        
        return curr;
    }
    
    string forward(int steps) {
        while (steps-- && !f.empty())
        {
            b.push(curr);
            curr = f.top();
            f.pop();
        }
        return curr;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */