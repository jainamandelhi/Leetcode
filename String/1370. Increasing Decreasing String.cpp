class Solution {
public:
    string sortString(string s) {
        vector<int>arr(26);
        for(int i=0;i<s.size();i++)
            arr[s[i]-'a']++;
        string ans="";
        while(1)
        {
            int flag=0;
            for(int i=0;i<26;i++)
            {
                if(arr[i])
                {
                    flag=1;
                    ans.push_back(i+'a');
                    arr[i]--;
                }
            }
            for(int i=25;i>=0;i--)
            {
                if(arr[i])
                {
                    flag=1;
                    ans.push_back(i+'a');
                    arr[i]--;
                }
            }
            if(flag)
                continue;
            break;
        }
        return ans;
    }
};