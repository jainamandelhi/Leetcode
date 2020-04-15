class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr1;
        vector<int> arr2;
        arr1 = nums;
        arr2 = nums;
        for(int i = 1; i < n; i++)
            arr1[i] *= arr1[i-1];
        for(int i = n-2; i >= 0; i--)
            arr2[i] *= arr2[i+1];
        vector<int>ans(n);
        for(int i = 0; i < n; i++)
        {
            if(i == 0)
            {
                ans[i] = arr2[i+1];
                continue;
            }
            if(i == n-1)
            {
                ans[i] = arr1[i-1];
                continue;
            }
            ans[i] = arr1[i-1]*arr2[i+1];
        }
        return ans;
    }
};