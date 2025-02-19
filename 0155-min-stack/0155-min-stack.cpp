class MinStack {
public:
    vector<int> v;
    MinStack() {  // constructor
        
    }
    
    void push(int val) {  //O(1)
        v.push_back(val);
    }
    
    void pop() {  // O(1)
        v.pop_back();
    }
    
    int top() {  // O(1)
        return v[v.size()-1];
    }
    
    int getMin() {
        int mn = v[0];
        for(int i=1;i<v.size();i++){
            mn = min(mn,v[i]);
        } 
        return mn;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */