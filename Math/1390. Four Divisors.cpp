class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            int a = nums[i];
            int tot = 0,ans = 0;
            for(int j=1;j<=sqrt(a);j++)
            {
                if(a%j == 0)
                {
                    ans += j;
                    tot++;
                    if(a/j != j)
                    {
                        tot++;
                        ans += a/j;
                    }
                }
            }
            if(tot == 4)
                sum += ans;
        }
        return sum;
    }
};