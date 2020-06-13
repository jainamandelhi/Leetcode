class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int i = 1;
        int j = nums[n-1]+1;
        int ans;
        while(i < j)
        {
            int mid = i + (j-i)/2;
            int temp = 0;
            for(int k = 0; k < n; k++)
            {
                temp += nums[k]/mid;
                if(nums[k]%mid)
                    temp++;
            }
            if(temp <= threshold)
            {
                ans = mid;
                j = mid;
            }
            else
                i = mid+1;
        }
        return ans;
    }
};