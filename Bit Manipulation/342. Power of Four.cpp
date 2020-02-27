class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<0)
            return 0;
        while(n)
        {
            if(n&1)
                break;
            n>>=1;
            if(n&1)
                return 0;
            n>>=1;
            
        }
        if(n>1 || n==0)
            return 0;
        else
            return 1;
    }
};