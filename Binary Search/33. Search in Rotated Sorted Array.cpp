class Solution {
public:
    int search(vector<int>& nums, int target) {
        int st = 0;
        int en = nums.size()-1;
        int n = en+1;
        int mid = st;
        if(n == 0)
            return -1;
        while(st < en)
        {
            mid = st+(en-st)/2;
            if(nums[mid] > nums[en])
                st = mid+1;
            else
                en = mid;
        }
        mid = st;
        if(target >= nums[0])
        {
            st = 0;
            en = mid-1;
            if(en < 0)
                en = n-1;
        }
        else
        {
            st = mid;
            en = n-1;
        }
        int ans = -1;
        while(st <= en)
        {
            mid = st + (en-st)/2;
            if(nums[mid] == target)
            {
                ans = mid;
                break;
            }
            if(nums[mid] < target)
                st = mid+1;
            else
                en = mid-1;
        }
        return ans;
    }
};