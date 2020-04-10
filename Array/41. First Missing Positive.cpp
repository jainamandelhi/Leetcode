class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i = 0; i <nums.size(); i++)
        {
            if(nums[i] >= 0)
                nums[i]--;
        }
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != i && nums[i] >= 0 && nums[i] < nums.size() && nums[nums[i]] != nums[i])
            {
                swap(nums[i],nums[nums[i]]);
                i--;
            }
        }
        for(int i = 0; i < nums.size(); i++)
        {
            if(i != nums[i])
                return i+1;
        }
        return nums.size()+1;
    }
};