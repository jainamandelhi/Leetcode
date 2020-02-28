class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans=0;
        while(a || b || c)
        {
            int p=a&1;
            int q=b&1;
            int r=c&1;
            if((p || q) != r)
            {
                if(r==1)
                    ans++;
                else
                {
                    ans++;
                    if(p && q)
                        ans++;
                }
            }
            a>>=1;
            b>>=1;
            c>>=1;
            cout<<a<<" "<<b<<" "<<c<<endl;
        }
        return ans;
    }
};