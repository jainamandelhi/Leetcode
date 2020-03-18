class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return 0;
        int a=0,y=x;
        while(y)
        {
            if(a>=INT_MAX/10)
                return 0;
            a=a*10+(y%10);
            y/=10;
        }
        if(a==x)
            return 1;
        return 0;
    }
};