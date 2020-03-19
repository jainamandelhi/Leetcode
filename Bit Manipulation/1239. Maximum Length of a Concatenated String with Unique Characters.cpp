int f(int a)
{
    int cnt=0;
    while(a)
    {
        cnt++;
        a = a&(a-1);
    }
    return cnt;
}
int dfs(int i,vector<int>&bin,int cnt,int temp)
{
    if(i==bin.size())
        return cnt;
    int a = 0, b = 0;
    if((temp & bin[i]) == 0)
    {
        a = dfs(i+1,bin,f(temp | bin[i]),temp|bin[i]);
    }
    b = dfs(i+1,bin,cnt,temp);
    return max(a,b);
}
class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<int>bin;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            string s = arr[i];
            int a = 0;
            int flag = 0;
            for(int i= 0;i<s.size();i++)
            {
                int b = s[i]-'a';
                b = 1<<b;
                if(b&a)
                {
                    flag = 1;
                    break;
                }
                a = a|b;
            }
            if(flag)
                continue;
            bin.push_back(a);
        }
        return dfs(0,bin,0,0);
    }
};