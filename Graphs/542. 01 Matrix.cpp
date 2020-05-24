class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        vector<vector<int> > ans(matrix.size(),vector<int>(matrix[0].size(),INT_MAX));
        int n = matrix.size();
        int m = matrix[0].size();
        queue<pair<int,int> >q;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(matrix[i][j] == 0){
                    q.push(make_pair(i,j));
                    ans[i][j] = 0;
                }
            }
        }
        while(!q.empty())
        {
            int fi = q.front().first;
            int se = q.front().second;
            q.pop();
            if(fi - 1 >= 0 && ans[fi-1][se] > ans[fi][se]+1)
            {
                ans[fi-1][se] = ans[fi][se]+1;
                q.push(make_pair(fi-1,se));
            }
            if(se - 1 >= 0 && ans[fi][se-1] > ans[fi][se]+1)
            {
                ans[fi][se-1] = ans[fi][se]+1;
                q.push(make_pair(fi,se-1));
            }
            if(fi + 1 < n && ans[fi+1][se] > ans[fi][se]+1)
            {
                ans[fi+1][se] = ans[fi][se]+1;
                q.push(make_pair(fi+1,se));
            }
            if(se + 1 < m && ans[fi][se+1] > ans[fi][se]+1)
            {
                ans[fi][se+1] = ans[fi][se]+1;
                q.push(make_pair(fi,se+1));
            }
        }
        return ans;
    }
};