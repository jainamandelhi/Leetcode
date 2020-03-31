class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        int n = A.size();
        vector<vector<double> >dp(n,vector<double>(K+1,INT_MIN));
        double sum = 0;
        vector<double>pre;
        for(int i=0;i<n;i++)
        {
            sum += A[i];
            pre.push_back(sum);
            dp[i][1] = sum/(i+1);
        }
        for(int k=2;k<=K;k++)
        {
            for(int i=k-1;i<n;i++)
            {
                for(int j=i-1;j>=0;j--)
                {
                    dp[i][k] = max(dp[j][k-1]+(pre[i]-pre[j])/(i-j),dp[i][k]);
                }
            }
        }
        double ans = INT_MIN;
        for(int i=1;i<=K;i++)
            ans = max(ans,dp[n-1][K]);
        return ans;
    }
};