class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        vector<int>arr(nums.size());
        for(int i=0;i<nums.size();i++)
        {
            if(i==0)
            {
                arr[i]=nums[i];
                continue;
            }
            if(i==1)
            {
                arr[i]=max(nums[i],nums[i-1]);
                continue;
            }
            arr[i]=max(arr[i-2]+nums[i],arr[i-1]);
        }
        return arr[nums.size()-1];
    }
};