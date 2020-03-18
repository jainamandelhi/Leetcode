int f(int n)
{
    int cnt = 0;
    while(n)
    {
        cnt++;
        n = n&(n-1);
    }
    return cnt;
}
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string>ans;
        for(int i=0;i<12;i++)
        {
            for(int j=0;j<60;j++)
            {
                if(f(i)+f(j) == num)
                {
                    string s="";
                    s = to_string(i) + ':';
                    if(j<10)
                    {
                        s = s + to_string(0) + to_string(j);
                    }
                    else
                    {
                        s = s + to_string(j);
                    }
                    ans.push_back(s);
                }
            }
        }
        return ans;
    }
};