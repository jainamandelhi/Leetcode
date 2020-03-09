class Solution {
public:
    int numberOfSubstrings(string s) {
        int a=0,b=0,c=0,ans=0;;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='a')
                a=i+1;
            else if(s[i]=='b')
                b=i+1;
            else
                c=i+1;
            ans+=min(a,min(b,c));
        }
        return ans;
    }
};