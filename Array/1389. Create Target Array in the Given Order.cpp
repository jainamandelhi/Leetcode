class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int>target(nums.size(),-1);
        for(int i = 0;i<nums.size();i++)
        {
            int a = index[i];
            if(target[a] == -1)
            {
                target[a] = nums[i];
                continue;
            }
            int j = a;
            while(j<nums.size() && target[j] != -1)
                j++;
            if(j == nums.size())
            {
                j = a;
                while(j>=0 && target[j] != -1)
                    j--;
            }
            while(j>a){
                target[j] = target[j-1];
                j--;
            }
            target[j] = nums[i];
        }
        return target;
    }
};