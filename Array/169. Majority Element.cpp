class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int j=0;
        int cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[j]==nums[i])
                cnt++;
            else
                cnt--;
            if(cnt==0)
            {
                j=i;
                cnt=1;
            }
        }
        return nums[j];
    }
};