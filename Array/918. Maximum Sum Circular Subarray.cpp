class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int curr = 0;
        int ans = INT_MIN;
        int index = 0;
        for(int i = 0; i < A.size(); i++)
        {
            if(curr < 0)
            {
                curr = 0;
                index = i;
            }
            curr += A[i];
            ans = max(ans,curr);
            ans = max(ans,A[i]);
        }
        int pref[A.size()];
        int suff[A.size()];
        curr = 0;
        for(int i = 0; i < A.size(); i++)
        {
            curr += A[i];
            if(i == 0)
            {
                pref[i] = A[i];
                continue;
            }
            pref[i] = max(curr,pref[i-1]);
        }
        curr = 0;
        for(int i = A.size()-1; i >= 0; i--)
        {
            curr += A[i];
            if(i == A.size()-1)
            {
                suff[i] = A[i];
                continue;
            }
            suff[i] = max(curr,suff[i+1]);
        }
        for(int i = 0; i < A.size()-1; i++)
            ans = max(ans,pref[i]+suff[i+1]);
        return ans;
    }
};