class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        int arr[n+1][n+1];
        string s1 = s;
        reverse(s1.begin(),s1.end());
        memset(arr,0,sizeof(arr));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s1[i-1] == s[j-1])
                    arr[i][j] = arr[i-1][j-1]+1;
                else
                    arr[i][j] = max(arr[i-1][j],arr[i][j-1]);
            }
        }
        return arr[n][n];
    }
};