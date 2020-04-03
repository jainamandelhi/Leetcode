class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxi = 0;
        for(int i=0;i<nums.size();i++)
            maxi = max(maxi,nums[i]);
        vector<int>ans(maxi+1);
        map<int,int>m;
        for(int i=0;i<nums.size();i++)
            m[nums[i]]++;
        for(int i=1;i<=maxi;i++)
        {
            if(i==1)
            {
                ans[i] = max(ans[i-1],m[i]*i);
                continue;
            }
            ans[i] = max(ans[i-1],m[i]*i+ans[i-2]);
        }
        return ans[maxi];
    }
};