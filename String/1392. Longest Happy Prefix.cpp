class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        vector<int> z(n,0);
        int l = 0;
        string ans = "";
        for(int i = 1, r = 0, l = 0; i < n; ++i)
        {
            if(i <= r)
                z[i] = min(z[i-l],r-i+1);
            while(z[i]+i < n && s[z[i]] == s[z[i]+i])
                z[i]++;
            if(i+z[i]-1 > r)
            {
                l = i;
                r = i+z[i]-1;
            }
        }
        for(int i = 1; i < n; ++i)
        {
            if(i+z[i] == n)
                l=max(l,z[i]);
        }
        for(int i = 0; i < l; ++i)
            ans += s[i];
        return ans;
    }
};
