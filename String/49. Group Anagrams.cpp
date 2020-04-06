class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string> >m;
        int n = strs.size();
        for(int i=0;i<n;i++)
        {
            string s = strs[i];
            sort(s.begin(),s.end());
            m[s].push_back(strs[i]);
        }
        vector<vector<string> >v;
        map<string,vector<string> > :: iterator itr;
        for(itr = m.begin(); itr != m.end(); itr++)
        {
            vector<string>temp;
            for(int i = 0; i < itr->second.size(); i++)
            {
                temp.push_back(itr->second[i]);
            }
            v.push_back(temp);
        }
        return v;
    }
};