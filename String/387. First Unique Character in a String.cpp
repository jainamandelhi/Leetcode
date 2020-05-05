class Solution {
public:
    bool canConstruct(string b, string a) {
        int n = a.size();
        int m = b.size();
        map<char,int>m1,m2;
        for(int i = 0; i < n; i++)
            m1[a[i]]++;
        for(int i = 0; i < m; i++)
            m2[b[i]]++;
        for(int i = 0; i < m; i++)
        {
            if(m1[b[i]] < m2[b[i]])
                return false;
        }
        return true;
    }
};