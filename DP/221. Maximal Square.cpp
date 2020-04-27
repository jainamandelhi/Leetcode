class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans = 0;
        if(matrix.size() == 0)
            return 0;
        vector<vector<int> >mat(matrix.size(),vector<int>(matrix[0].size()));
        for(int i = 0; i < mat.size(); i++)
        {
            for(int j = 0; j < mat[0].size(); j++)
            {
                if(matrix[i][j] == '1')
                    mat[i][j] = 1;
            }
        }
        for(int i = 0; i < mat.size(); i++)
        {
            for(int j = 0; j < mat[i].size(); j++)
            {
                if(mat[i][j] == 1)
                {
                    if(i-1 >= 0 && j-1 >= 0 && mat[i-1][j-1] && mat[i-1][j] && mat[i][j-1])
                        mat[i][j] = min(mat[i][j-1],min(mat[i-1][j],mat[i-1][j-1]))+1;
                }
                ans = max(ans,mat[i][j]*mat[i][j]);
            }
        }
        return ans;
    }
};