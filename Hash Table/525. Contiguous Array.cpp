class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int ans = 0;
        map<int,int>m;
        m[0] = -1;
        int sum = 0;
        for(int i = 0; i <nums.size(); i++)
        {
            if(nums[i] == 0)
                sum--;
            sum += nums[i];
            if(m.find(sum) != m.end())
            {
                ans = max(ans,i-m[sum]);
                continue;
            }
            m[sum] = i;
        }
        return ans;
    }
};