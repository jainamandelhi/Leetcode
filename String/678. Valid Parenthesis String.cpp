class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        if(n == 1)
        {
            if(s[0] == '*')
                return 1;
            else
                return 0;
        }
       int ans = 0;
        int lo = 0, hi = 0;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '(')
            {
                lo++;
                hi++;
            }
            else if(s[i] == ')')
            {
                lo--;
                hi--;
            }
            else
            {
                lo--;
                hi++;
            }
            if(hi < 0)
                return 0;
            lo = max(lo,0);
        }
        return lo == 0;
    }
};