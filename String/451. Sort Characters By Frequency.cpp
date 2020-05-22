bool f(const pair<char,int>&p1, const pair<char,int>&p2)
{
    return p1.second > p2.second;
}
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>m;
        for(int i = 0; i < s.size(); i++)
            m[s[i]]++;
        vector<pair<int,int> >v;
        unordered_map<char,int> :: iterator itr;
        for(itr = m.begin(); itr != m.end(); itr++)
            v.push_back(make_pair(itr -> first, itr -> second));
        sort(v.begin(), v.end(), f);
        string ans = "";
        for(int i = 0; i < v.size(); i++)
        {
            for(int j = 0; j < v[i].second; j++)
                ans.push_back(v[i].first);
        }
        return ans;
    }
};