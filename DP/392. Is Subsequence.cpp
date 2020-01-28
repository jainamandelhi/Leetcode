class Solution {
public:
    bool isSubsequence(string s, string t) {
        vector<vector<int> >arr(s.size()+1,vector<int>(t.size()+1));
        for(int i=1;i<=s.size();i++)
        {
            for(int j=1;j<=t.size();j++)
            {
                if(s[i-1]==t[j-1])
                    arr[i][j]=arr[i-1][j-1]+1;
                else
                    arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
            }
        }
        if(arr[s.size()][t.size()]==s.size())
            return 1;
        else
            return 0;
    }
};