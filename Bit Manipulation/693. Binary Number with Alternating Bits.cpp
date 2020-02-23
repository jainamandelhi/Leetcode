class Solution {
public:
    bool hasAlternatingBits(int n) {
        int flag=0;
        int m=n;
        while(n)
        {
            if(flag==0 && n%2==1)
            {
                n/=2;
            }
            else if(flag==1 && n%2==0)
            {
                n/=2;
            }
            else
                break;
            flag=!flag;
        }
        if(!n)
            return true;
        n=m;
        while(n)
        {
            if(flag==0 && n%2==0)
            {
                n/=2;
            }
            else if(flag==1 && n%2==1)
            {
                n/=2;
            }
            else
                break;
            flag=!flag;
        }
        if(!n)
            return true;
        return false;
    }
};