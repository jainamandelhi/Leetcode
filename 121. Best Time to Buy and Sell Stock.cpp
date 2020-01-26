class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int n=prices.size();
        if(n==0)
            return 0;
        int maxi[n],mini[n];
        for(int i=0;i<n;i++)
        {
            if(i==0)
                mini[i]=prices[i];
            else
                mini[i]=min(prices[i],mini[i-1]);
        }
        for(int i=n-1;i>=0;i--)
        {
            if(i==n-1)
                maxi[i]=prices[i];
            else
                maxi[i]=max(prices[i],maxi[i+1]);
        }
        int ans=0;
        for(int i=0;i<n;i++)
            ans=max(ans,maxi[i]-mini[i]);
        return ans;
    }
};