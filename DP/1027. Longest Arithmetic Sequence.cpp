class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int n = A.size();
        int maxi = 1;
        unordered_map<int,unordered_map<int,int> >m;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                m[i][A[i]-A[j]] = m[j][A[i]-A[j]]+1;
                maxi = max(maxi,m[i][A[i]-A[j]]);
            }
        }
        return maxi+1;
    }
};