class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        int n = A.size();
        vector<int>ans(n);
        int maxi = 0;
        for(int i = 0; i < K; i++)
        {
            maxi = max(maxi,A[i]);
            ans[i] = maxi*(i+1);
        }
        for(int i = K; i < n; i++)
        {
            maxi = 0;
            for(int j = i; j >= i-K+1; j--)
            {
                maxi = max(maxi , A[j]);
                ans[i] = max(ans[i] , ans[j-1]+maxi*(i-j+1));
            }
        }
        return ans[n-1];
    }
};