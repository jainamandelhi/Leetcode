class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int>s;
        int sum = 0;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if(sum == k)
                ans += s[sum - k]+1;
            else if(s.find(sum - k) != s.end())
                ans += s[sum-k];
            s[sum]++;
        }
        return ans;
    }
};