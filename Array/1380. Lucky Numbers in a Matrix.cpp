class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector< int >ans;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int a=matrix[i][j];
                int mini=INT_MIN;
                for(int k=0;k<n;k++)
                    mini=max(mini,matrix[k][j]);
                if(a!=mini)
                    continue;
                mini=INT_MAX;
                for(int k=0;k<m;k++)
                    mini=min(mini,matrix[i][k]);
                if(mini==a)
                    ans.push_back(a);
            }
        }
        return ans;
    }
};