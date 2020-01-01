int r=0;
int bs(int a,int b,int i,int j,vector<int>&nums)
{
    if(i<=j){
    int mid=i+(j-i)/2;
    //cout<<a<<" "<<b<<" "<<nums[mid]<<endl;
    if(nums[mid]+a+b==0){
     //   cout<<432<<endl;
        return mid;
    }
    else if(nums[mid]+a+b<0)
        return bs(a,b,mid+1,j,nums);
    else
        return bs(a,b,i,mid-1,nums);
    }
    return -1;
}
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       sort(nums.begin(),nums.end());
        set<tuple<int,int,int> >s;
        vector<vector<int> >ans;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0)
                break;
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[i]+nums[j]>0)
                    break;
                int k = bs(nums[i],nums[j],j+1,nums.size()-1,nums);
                //cout<<nums[i]<<" "<<nums[j]<<" "<<k<<endl;
                if(k==-1)
                    continue;
                tuple t=make_tuple(nums[i],nums[j],nums[k]);
                if(s.find(t)==s.end())
                {
                    vector<int>arr;
                    arr.push_back(nums[i]);
                    arr.push_back(nums[j]);
                    arr.push_back(nums[k]);
                    ans.push_back(arr);
                    s.insert(t);
                }
            }
        }
        return ans;
    }
};