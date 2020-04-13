class Solution {
public:
    vector<int> closestDivisors(int num) {
        int a = sqrt(++num);
        int b = num+1;
        b = sqrt(b);
        int a1,a2,b1,b2;
        a1 = a;
        while(num%a1)
            a1--;
        a2 = num/a1;
        b1 = b;
        num++;
        while(num%b1)
            b1--;
        b2 = num/b1;
        vector<int>ans;
        if(abs(a1-a2) < abs(b1-b2))
        {
            ans.push_back(a1);
            ans.push_back(a2);
        }
        else
        {
            ans.push_back(b1);
            ans.push_back(b2);
        }
        return ans;
    }
};