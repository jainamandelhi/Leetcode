class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        int n = A.size();
        vector<int>ans(n,1);
        int maxi = 0;
        int dp[n][n];
        unordered_map<int,int>m;
        for(int i = 0;i < n; i++)
        {
            m[A[i]] = i;
            for(int j = 0; j < i; j++)
            {
                dp[j][i] = 2;
                if(m.find(A[i]-A[j]) != m.end() && A[i]-A[j] < A[j])
                {
                    dp[j][i] = max(dp[j][i],dp[m[A[i]-A[j]]][j]+1);
                    maxi = max(maxi,dp[j][i]);
                }
            }
        }
        return maxi;
    }
};