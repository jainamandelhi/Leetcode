class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        int n=S.size();
        queue<string>q;
        set<string>vis;
        q.push(S);
        vector<string>ans;
        //ans.push_back(S);
        vis.insert(S);
        while(!q.empty())
        {
            string s1=q.front();
            q.pop();
            for(int i=0;i<n;i++)
            {
                if(s1[i]>='a' && s1[i]<='z')
                {
                    int a=s1[i];
                    a-=32;
                    char b=a;
                    s1[i]=b;
                    if(vis.find(s1)==vis.end())
                    {
                        vis.insert(s1);
                        q.push(s1);
                    }
                }
                if(s1[i]>='A' && s1[i]<='Z')
                {
                    int a=s1[i];
                    a+=32;
                    char b=a;
                    s1[i]=b;
                    if(vis.find(s1)==vis.end())
                    {
                        vis.insert(s1);
                        q.push(s1);
                    }
                }
            }
        }
        set<string>::iterator itr;
        for(itr=vis.begin();itr!=vis.end();itr++)
            ans.push_back(*itr);
        return ans;
    }
};