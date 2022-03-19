class FreqStack {
    int maxFreq;
    unordered_map <int, int> freq;
    unordered_map <int, stack<int>> stacks;
public:
    FreqStack() {
        maxFreq = 0;
    }
    
    void push(int val) {
        ++freq[val];
        maxFreq = max(maxFreq, freq[val]);
        stacks[freq[val]].push(val);
    }
    
    int pop() {
        int number = stacks[maxFreq].top();
        stacks[maxFreq].pop();
        --freq[number];
        
        if (stacks[maxFreq].empty())
            --maxFreq;
        
        return number;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
