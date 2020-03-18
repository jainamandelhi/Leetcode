class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int arr[32] = {0};
        for(int i=31;i>=0;i--)
        {
            int a = 1<<i;
            for(int j=0;j<n;j++)
            {
                int b = nums[j]&a;
                if(b)
                    b=1;
                else
                    b=0;
                arr[i] += (b);
            }
        }
        for(int i=0;i<32;i++)
            ans = ans+arr[i]*(n-arr[i]);
        return ans;
    }
};