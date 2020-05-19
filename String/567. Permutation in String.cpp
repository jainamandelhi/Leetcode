class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char,int>m1,m2,m;
        for(int i = 0; i < s1.size(); i++)
            m1[s1[i]]++;
        for(int i = 0; i < s2.size(); i++)
            m2[s2[i]]++;
        int flag = 0;
        int i = 0, j = 0;
        while(j < s2.size())
        {
            if(m1.find(s2[j]) == m1.end())
            {
                m.clear();
                i = j+1;
                j++;
                flag = 0;
                continue;
            }
            m[s2[j]]++;
            if(m1[s2[j]] == m[s2[j]])
                flag++;
            while(m1[s2[j]] < m[s2[j]])
            {
                if(m[s2[i]] == m1[s2[i]])
                    flag--;
                m[s2[i]]--;
                if(m[s2[i]] == 0)
                    m.erase(s2[i]);
                i++;
            }
            if(flag == m1.size())
                return 1;
            j++;
        }
        return 0;
    }
};