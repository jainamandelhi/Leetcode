class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int>temp;
        int count = 0;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i] == 0)
                count++;
            else
                temp.push_back(nums[i]);
        }
        while(count--)
            temp.push_back(0);
        nums = temp;
    }
};