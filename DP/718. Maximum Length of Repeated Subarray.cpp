class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int n = A.size();
        int m = B.size();
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        int maxi = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1;j <= m; j++)
            {
                if(A[i-1] == B[j-1])
                    dp[i][j] = dp[i-1][j-1]+1;
                maxi = max(dp[i][j],maxi);
            }
        }
        return maxi;
    }
};