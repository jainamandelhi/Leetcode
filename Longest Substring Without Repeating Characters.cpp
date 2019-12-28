class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0,temp=0;
        int i=0,j=0;
        unordered_map<char,int>m;
        int n=s.size();
        while(j<n)
        {
            if(m[s[j]]==0)
            {
                m[s[j]]++;
                ans=max(ans,j-i+1);
                j++;
            }
            else
            {
                while(m[s[j]]!=0)
                {
                    m[s[i]]--;
                    i++;
                }
            }
            cout<<i<<" "<<j<<" "<<m[s[j]]<<endl;
        }
        //ans=max(ans,j-i+1);
        return ans;
    }
};