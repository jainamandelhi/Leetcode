class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        int n=nums.size(),flag=0;
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(nums[i]+nums[j]==target)
                {
                    ans.push_back(i);
                    ans.push_back(j);
                    flag=1;
                    break;
                }
            }
            if(flag==1)
                break;
        }
        return ans;
    }
};