class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat[0].size();
        int n = mat.size();
        int j = 0;
        while(j < m)
        {
            int jt = j;
            vector<int>temp;
            int i = 0;
            while(i < n && jt < m)
            {
                temp.push_back(mat[i][jt]);
                i++;
                jt++;
            }
            sort(temp.begin(),temp.end());
            int k = 0;
            jt = j;
            i = 0;
            while(jt < m && i < n)
            {
                mat[i][jt] = temp[k++];
                jt++;
                i++;
            }
            j++;
        }
        int i = 0;
        while(i < n)
        {
            int it = i;
            vector<int>temp;
            j = 0;
            while(it < n && j < m)
            {
                temp.push_back(mat[it][j]);
                it++;
                j++;
            }
            sort(temp.begin(),temp.end());
            int k = 0;
            it = i;
            j = 0;
            while(j < m && it < n)
            {
                mat[it][j] = temp[k++];
                j++;
                it++;
            }
            i++;
        }
        return mat;
    }
};