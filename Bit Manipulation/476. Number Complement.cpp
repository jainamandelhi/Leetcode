class Solution {
public:
    int findComplement(int n) {
        int i=0,ans=0;
        while(n)
        {
            int a=n%2;
            n/=2;
            a=!a;
            ans=ans+a*pow(2,i++);
        }
        return ans;
    }
};