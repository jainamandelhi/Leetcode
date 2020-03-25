class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        int n = pairs.size();
        vector<int>ans(n);
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(pairs[i][0] > pairs[j][1])
                    ans[i] = max(ans[i],ans[j]+1);
            }
        }
        return ans[n-1] + 1;
    }
};