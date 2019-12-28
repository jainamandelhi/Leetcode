class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        string s1="";
        if(!n)
            return s1;
        int ini=0,fin=0;
        int dp[n][n];
        for(int i=0;i<n;i++)
            dp[i][i]=1;
        //int maxi=1;
        for(int i=0;i<n-1;i++)
            if(s[i]==s[i+1])
            {
                dp[i][i+1]=1;
                ini=i;
                fin=i+1;
            }
            else
                dp[i][i+1]=0;
        for(int d=2;d<n;d++)
        {
            for(int i=0;i<n;i++)
            {
                if(i+d>=n)
                    break;
                if(s[i]!=s[i+d])
                    dp[i][i+d]=0;
                else if(dp[i+1][i+d-1]==1)
                {
                    dp[i][i+d]=1;
                    //maxi=d+1;
                    ini=i;
                    fin=i+d;
                }
                else
                    dp[i][i+d]=0;
            }
        }
        for(int j=ini;j<=fin;j++)
            s1.push_back(s[j]);
        return s1;
    }
};