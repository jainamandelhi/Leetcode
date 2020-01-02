int bs(int a,int i,int j,vector<int>&nums,int diff,int target,int ans)
{
    if(i<=j){
    int mid=i+(j-i)/2;
    //cout<<a<<" "<<b<<" "<<nums[mid]<<endl;
    if(abs(a+nums[mid]-target)<diff){
        ans=a+nums[mid];
        diff=abs(a+nums[mid]-target);
    }
    if(nums[mid]+a<target)
        return bs(a,mid+1,j,nums,diff,target,ans);
    else
        return bs(a,i,mid-1,nums,diff,target,ans);
    }
    return ans;
}
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans,diff=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                
                if(j+1==nums.size())
                    break;
                int k =bs(nums[i]+nums[j],j+1,nums.size()-1,nums,INT_MAX,target,0);
                if(abs(k-target)<diff)
                {
                    ans=k;
                    diff=abs(k-target);
                }
                //cout<<nums[i]<<" "<<nums[j]<<" "<<k<<endl;
            }
        }
        return ans;
    }
};