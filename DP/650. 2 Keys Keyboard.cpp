class Solution {
public:
    int minSteps(int n) {
        vector<int>dp(n+1);
        for(int i=2;i<=n;i++)
        {
            dp[i] = i;
            for(int j=i-1;j>1;j--)
            {
                if(i%j == 0)
                    dp[i] = min(dp[i],dp[i/j]+dp[j]);
            }
        }
        return dp[n];
    }
};