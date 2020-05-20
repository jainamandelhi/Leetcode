bool f(const pair<string,int>&p1, const pair<string,int>&p2)
    {
        if(p1.first.size() == p2.first.size())
            return p1.second < p2.second;
        return p1.first.size() < p2.first.size();
    }
class Solution {
public:
    string arrangeWords(string text) {
        char c = text[0];
        c += 32;
        text[0] = c;
        vector<pair<string,int> >s;
        string s1 = "";
        for(int i = 0; i < text.size(); i++)
        {
            if(text[i] == ' ')
            {
                s.push_back(make_pair(s1,i));
                s1 = "";
                continue;
            }
            s1.push_back(text[i]);
        }
    s.push_back(make_pair(s1,text.size()));
    sort(s.begin(), s.end(), f);
    c = s[0].first[0];
    c -= 32;
    s[0].first[0] = c;
    string ans = "";
    for(int i = 0; i < s.size(); i++)
    {
        ans += (s[i].first);
        if(i < s.size()-1)
            ans.push_back(' ');
    }
    return ans;
    }
};