class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans=0;
        //return n;
        int a=32;
        while(a--)
        {
            ans<<=1;
            ans=ans|(n&1);
            n>>=1;
            cout<<ans<<endl;
        }
        return ans;
    }
};