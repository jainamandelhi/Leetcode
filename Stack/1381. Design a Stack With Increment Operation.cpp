stack<int>s;
int n;
class CustomStack {
public:
    CustomStack(int maxSize) {
        s=stack<int>();
        n=maxSize;
    }
    
    void push(int x) {
        if(s.size()==n)
            return;
        s.push(x);
    }
    
    int pop() {
        if(s.size()==0)
            return -1;
        int a=s.top();
        s.pop();
        return a;
    }
    
    void increment(int k, int val) {
        stack<int>temp;
        if(s.size()>=k)
        {
            int t=s.size()-k;
            while(t--){
            temp.push(s.top());
            s.pop();
            }
            while(s.size())
            {
                temp.push(s.top()+val);
                s.pop();
            }
            while(temp.size())
            {
                s.push(temp.top());
                temp.pop();
            }
        }
        else
        {
            while(s.size())
            {
                temp.push(s.top()+val);
                s.pop();
            }
            while(temp.size())
            {
                s.push(temp.top());
                temp.pop();
            }
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */