class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int a=0;
        for(int i=0;i<nums.size();i++)
            a^=nums[i];
        int b=a^(a&(a-1)),p=0,q=0;
        for(int i=0;i<nums.size();i++)
        {
            if(b&nums[i])
                p^=nums[i];
            else
                q^=nums[i];
        }
        vector<int>ans;
        ans.push_back(p);
        ans.push_back(q);
        return ans;
    }
};