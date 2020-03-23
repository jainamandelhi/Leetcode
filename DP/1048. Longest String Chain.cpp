class Solution {
public:
    static bool compare(string &a,string &b)
    {
        return a.size()<b.size();
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(),words.end(),compare);
        int ans = 0;
        unordered_map<string,int>m;
        for(int i=0;i<n;i++)
        {
            string s = words[i];
            if(s.size()==1)
            {
                m[s] = 1;
                continue;
            }
            m[s] = 1;
            for(int j=0;j<s.size();j++)
            {
                m[s] = max(m[s.substr(0,j) + s.substr(j+1,s.size()-j-1)]+1,m[s]);
                ans = max(m[s],ans);
            }
        }
        return ans;
    }
};