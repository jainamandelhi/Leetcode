class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int maxi = 0;
        int cnt = 0;
        int n = seq.size();
        for(int i = 0; i < n; i++)
        {
            if(seq[i] == '(')
                cnt++;
            else
                cnt--;
            maxi = max(maxi,cnt);
        }
        maxi /= 2;
        maxi++;
        cnt = 0;
        vector<int>ans(n);
        for(int i = 0; i < n; i++)
        {
            if(seq[i] == '(')
                cnt++;
            else
                cnt--;
            if(cnt >= maxi)
                ans[i] = 0;
            else
                ans[i] = 1;
            if(seq[i] == ')' && cnt+1 == maxi)
                ans[i] = 0;
        }
        return ans;
    }
};