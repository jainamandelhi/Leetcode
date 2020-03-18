bool check(int p,int q,int n,int m)
{
    if(p<n && q<m && p>=0 && q>=0)
        return 1;
    return 0;
}
void dfs(int i, int j, vector<vector<int> >&image, vector<vector<int> >&vis,int c,int n,int m,int l)
{
    int x[4]={1,-1,0,0};
    int y[4]={0,0,1,-1};
    for(int t=0;t<4;t++)
    {
        int p = i+x[t];
        int q = j+y[t];
        if(check(p,q,n,m) && image[p][q] == l && !vis[p][q])
        {
            image[p][q] = c;
            vis[p][q] = 1;
            dfs(p,q,image,vis,c,n,m,l);
        }
            
    }
}
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size(),m = image[0].size();
        vector<vector<int> >vis(n,vector<int>(m));
        vis[sr][sc] = 1;
        dfs(sr,sc,image,vis,newColor,n,m,image[sr][sc]);
        image[sr][sc] = newColor;
        return image;
    }
};