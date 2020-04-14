class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int n = shift.size();
        int temp = 0;
        for(int i = 0; i < n; i++)
        {
            if(shift[i][0] == 0)
                temp = temp - (shift[i][1]);
            else
                temp = temp + (shift[i][1]);
        }
        string s1 = s;
        int flag = 0;
        if(temp < 0)
            flag = 1;
        temp = abs(temp);
        temp %= (s.size());
        if(flag)
        {
            for(int i = 0; i < s.size(); i++)
            {
                int j = i-temp;
                if(j < 0)
                    j += s.size();
                s1[j] = s[i];
            }
        }
        else
        {
            for(int i = 0; i < s.size(); i++)
            {
                int j = i+temp;
                if(j >= s.size())
                    j -= s.size();
                s1[j] = s[i];
            }
        }
        return s1;
    }
};