class StockSpanner {
public:
    stack<pair<int,int> >st;
    int i = 0;
    StockSpanner() {
        st.push(make_pair(-1,INT_MAX));
    }
    
    int next(int price) {
        while(price >= st.top().second)
            st.pop();
        int ans = i - st.top().first;
        st.push(make_pair(i++,price));
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */