class Solution {
public:
    string removeKdigits(string num, int k) {
        string s = num;
        reverse(s.begin() , s.end());
        int i = s.size() - 1;
        while(i >= 0 && s.size() && k)
        {
            if(i-1 < 0)
                break;
            if(i - 1 >= 0 && s[i] > s[i-1])
            {
                s.erase(i,1);
                k--;
                while(s.size() && s[s.size()-1] == '0')
                s.pop_back();
                i = s.size() - 1;
            }
            else
                i--;
        }
        reverse(s.begin() , s.end());
        
        while(s.size() && k--)
            s.pop_back();
        
        if(!s.size())
            s.push_back('0');
            
        return s;
    }
};