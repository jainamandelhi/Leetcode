class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            string s = words[i];
            int masks = 0;
            for(int j=0;j<s.size();j++)
            {
                masks = masks|(1<<(s[j]-'a'));
            }
            ans.push_back(masks);
        }
        int maxi = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if((ans[i]&ans[j])==0)
                    maxi = max(maxi,int(words[i].size())*int(words[j].size()));
            }
        }
        return maxi;
    }
};