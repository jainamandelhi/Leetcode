class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int arr[32] = {0};
        for(int i=0;i<32;i++)
        {
            for(int j=0;j<nums.size();j++)
            {
                int a = nums[j]&(1<<i);
                if(a)
                    arr[i]++;
            }
        }
        int ans = 0;
        for(int i=0;i<32;i++)
        {
            if(arr[i]%3)
                ans = ans|(1<<i);
        }
        return ans;
    }
};