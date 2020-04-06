class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(!n)
            return 1;
        vector<int>ans(n+1);
        ans[1]  = 9;
        for(int i = 2; i <= n; i++)
            ans[i] = ans[i-1]*(11-i);
        int out = 0;
        for(int i = 1; i <= n; i++)
            out += ans[i];
        return out+1;
    }
};