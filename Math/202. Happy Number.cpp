class Solution {
public:
    bool isHappy(int n) {
        set<int>s;
        while(s.find(n) == s.end())
        {
            if(n == 1)
                return 1;
            int a = 0;
            s.insert(n);
            while(n)
            {
                int temp = n%10;
                n /= 10;
                a = a+temp*temp;
            }
            n = a;
        }
        return 0;
    }
};