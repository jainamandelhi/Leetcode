class Solution {
public:
    int bs(vector<int>&nums,int i,int j,int target)
    {
        if(i>j)
            return -1;
        int mid = i+(j-i)/2;
        if(nums[mid] == target)
            return mid;
        else if(nums[mid] > target)
            return bs(nums,i,mid-1,target);
        else
            return bs(nums,mid+1,j,target);
    }
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return -1;
        return bs(nums,0,nums.size()-1,target);
    }
};