class Solution {
public:
    int integerBreak(int n) {
        int maxi = 0;
        for(int i = 2;i <= n ;i++)
        {
            int a = n/i;
            int b = n%i;
            int ans = pow(a+1,b) * pow(a,i-b);
            maxi = max(maxi,ans);
        }
        return maxi;
    }
};