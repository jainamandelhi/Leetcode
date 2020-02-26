class Solution {
public:
    int getSum(int a, int b) {
        int c=a,d=b;
        while(c)
        {
            int a=c&d;
            a=(unsigned int)a<<1;
            d=c^d;
            c=a;
        }
        return d;
    }
};