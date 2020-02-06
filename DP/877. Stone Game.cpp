vector<vector<int> >dp(501,vector<int>(501,-1));
int f(vector<int>&piles,int i,int j,int sum)
{
    if(i>j)
        return sum;
    if(dp[i][j]!=-1)
        return dp[i][j];
    int a=0,b=0,c=0,d=0;
    a+=f(piles,i+1,j-1,sum+piles[i]);
    b+=f(piles,i+2,j,sum+piles[i]);
    c+=f(piles,i+1,j-1,sum+piles[j]);
    d+=f(piles,i,j-2,sum+piles[j]);
    return dp[i][j]=max(a,max(b,max(c,d)));
}
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int sum=0;
        dp=vector<vector<int> >(501,vector<int>(501,-1));
        for(int i=0;i<piles.size();i++)
            sum+=piles[i];
        int sum1;
        sum1=f(piles,0,piles.size()-1,0);
        cout<<sum1;
        return sum1>sum-sum1;
    }
};