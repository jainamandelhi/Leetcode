vector<int>arr;
class NumArray {
public:
    NumArray(vector<int>& nums) {
        arr=vector<int>();
        for(int i=0;i<nums.size();i++)
            arr.push_back(nums[i]);
        for(int i=1;i<nums.size();i++)
            arr[i]+=arr[i-1];
        for(int i=0;i<arr.size();i++)
            cout<<arr[i]<<" ";
    }
    
    int sumRange(int i, int j) {
        int temp;
        if(i==0 || j==0)
            temp=arr[j];
        else
            temp=arr[j]-arr[i-1];
        return temp;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */