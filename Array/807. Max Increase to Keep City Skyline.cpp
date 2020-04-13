class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int>rows;
        vector<int>columns;
        for(int i = 0; i < grid.size(); i++)
        {
            int maxi = 0;
            for(int j = 0; j < grid[0].size(); j++)
            {
                maxi = max(maxi,grid[i][j]);
            }
            rows.push_back(maxi);
        }
        for(int j = 0; j < grid[0].size(); j++)
        {
            int maxi = 0;
            for(int i = 0; i < grid.size(); i++)
            {
                maxi = max(maxi,grid[i][j]);
            }
            columns.push_back(maxi);
        }
        int ans = 0;
        for(int i = 0; i < rows.size(); i++)
        {
            for(int j = 0; j < columns.size(); j++)
                ans += abs(grid[i][j]-min(rows[i],columns[j]));
        }
        return ans;
    }
};