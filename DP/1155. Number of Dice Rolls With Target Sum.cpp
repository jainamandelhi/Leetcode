class Solution {
public:
    int dp[32][32][1002];
    int mod = 1000000007;
    int fun(int d,int f,int target)
    {
        if(target == 0 && d == 0)
            return 1;
        if(target < 0 || d == 0)
            return 0;
        if(dp[d][f][target] != -1)
            return dp[d][f][target];
        int a = 0;
        for(int i = 1; i <= f; i++)
        {
            a = (a + fun(d-1,f,target-i))%mod;  
        }
        return dp[d][f][target] = a;
    }
    int numRollsToTarget(int d, int f, int target) {
        for(int i=0;i<=31;i++)
            for(int j=0;j<=31;j++)
                for(int k=0;k<=1001;k++)
                    dp[i][j][k]=-1;
        return fun(d,f,target);
    }
};