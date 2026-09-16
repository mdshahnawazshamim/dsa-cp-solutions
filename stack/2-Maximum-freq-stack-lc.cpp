class FreqStack {
public:

    unordered_map<int,stack<int>> fs;
    unordered_map<int,int> um;
    FreqStack() {
        
    }
    
    void push(int val) {
        int x = val;
        um[x]++;
        int f = um[x];

        if(fs.find(f)==fs.end())
        {
            stack<int> s;
            fs[f]=s;
        }
        fs[f].push(x);

        
    }
    
    int pop() {
        
        int f = fs.size();
        int ele = fs[f].top();
        fs[f].pop();

        if(fs[f].size()==0)
        {
            fs.erase(f);
        }
        um[ele]--;
        return ele;
        
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
