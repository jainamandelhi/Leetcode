class Solution {
public:
    int rangeBitwiseAnd(int m1, int n1) {
        long n_temp = n1;
        long m = m1;
        long n = n1;
        long cnt1 = 0;
        while(n_temp)
        {
            cnt1++;
            n_temp >>= 1;
        }
        if(!cnt1)
            return 0;
        if(m < (1<<(cnt1-1)))
            return 0;
        long ans = m;
        for(long i = m+1; i <= n; i++)
            ans &= i;
        if(ans > INT_MAX)
            ans = 0;
        return ans;
    }
};