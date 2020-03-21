class Solution {
public:
    #define ll int
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<int>ans(N);
        vector<vector<ll> >arr(N+1);
        for(int i=0;i<paths.size();i++)
        {
            int a = paths[i][0]-1;
            int b = paths[i][1]-1;
            arr[a].push_back(b);
            arr[b].push_back(a);
        }
        for(int i=0;i<N;i++)
        {
            vector<ll>s(5);
            int col = 1;
            for(int j=0;j<arr[i].size();j++)
            {
                s[ans[arr[i][j]]]++;
            }
            while(s[col])
                col++;
            ans[i] = col;
        }
        return ans;
    }
};