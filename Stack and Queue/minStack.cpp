class MinStack {
public:
    /** initialize your data structure here. */
    stack<long long> s;
    int count;
    long long minEle;
    
    MinStack() {
        this->count = 0;
        this->minEle = 0;
    }
    
    void push(int val) {
        if(count == 0){
            minEle = val;
            s.push(val);
        }
        else if(val < minEle){
            long long temp = 2 * (long long)val - minEle;
            s.push(temp);
            //s.push(2 * (long long)val - minEle);
            minEle = val;
        }
        else{
            s.push(val);
        }
       count++;
    }
    
    void pop() {
        if(count == 0){
            return;
        }
        
        if(s.top() > minEle){
            s.pop();
            count--;
        }
        else{
            long long temp = 2 * (long long)minEle - s.top();
            minEle = temp;
            //minEle = 2 * (long long)minEle - s.top();
            s.pop();
            count--;
            if(count == 0){
                minEle = 0;
            }
        }
    }
    
    int top() {
        if(count == 0){
            return -1;
        }
        long long temp = s.top();
        return temp < minEle ? minEle : temp;
        //return s.top();
    }
    
    int getMin() {
        if(count == 0){
            return -1;
        }
        return minEle;
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