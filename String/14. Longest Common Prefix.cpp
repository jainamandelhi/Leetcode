class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        if(n==0)
            return "";
        int flag=0, ans=-1;
        for(int i=0;i<INT_MAX;i++)
        {
            char a;
            if(i<strs[0].size())
            {
                a=strs[0][i];
            }
            else
                break;
            for(int j=0;j<strs.size();j++)
            {
                if(strs[j][i]==a)
                    continue;
                else
                {
                    flag=1;
                    break;
                }
            }
            if(flag)
                break;
            ans++;
        }
        string s="";
        if(ans<0)
            return s;
        for(int i=0;i<=ans;i++)
            s+=strs[0][i];
        return s;
    }
};