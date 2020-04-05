class Solution {
public:
    int minSteps(string s, string t) {
        vector<int>v1(26);
        vector<int>v2(26);
        for(int i =0; i < s.size(); i++)
            v1[s[i]-'a']++;
        for(int i =0; i < t.size(); i++)
            v2[t[i]-'a']++;
        int ans = 0;
        for(int i = 0; i < 26; i++)
            ans = ans + max(0,v1[i]-v2[i]);
        return ans;
    }
};