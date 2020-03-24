class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int a[n],b[n];
        a[0] = -1*prices[0];
        b[0] = 0;
        for(int i=1;i<n;i++)
        {
            a[i] = max(a[i-1], b[i-1]-prices[i]);
            b[i] = max(b[i-1],a[i-1]-fee+prices[i]);
        }
        return b[n-1];
    }
};