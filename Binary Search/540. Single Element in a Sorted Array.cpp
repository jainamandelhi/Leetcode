class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int i = 0; 
        int j = n-1;
        while(i <= j)
        {
            int mid = i + (j-i)/2;
            if(mid == i && i == j)
                return nums[mid];
            if(mid - 1 >= i && nums[mid] != nums[mid-1] && mid + 1 <= j && nums[mid] != nums[mid+1])
                return nums[mid];
            if(mid - 1 >= i && nums[mid-1] == nums[mid])
            {
                if(mid % 2)
                    i = mid+1;
                else
                    j = mid-2;
            }
            else
            {
                if(mid % 2 == 0)
                    i = mid+2;
                else
                    j = mid-1;
            }
        }
        return -1;
    }
};