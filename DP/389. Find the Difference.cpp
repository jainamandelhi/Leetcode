class Solution {
public:
    char findTheDifference(string s, string t) {
        int n=s.size(),m=t.size();
        int a=0;
        for(int i=0;i<n;i++)
            a^=s[i];
        for(int i=0;i<m;i++)
            a^=t[i];
        return a;
    }
};