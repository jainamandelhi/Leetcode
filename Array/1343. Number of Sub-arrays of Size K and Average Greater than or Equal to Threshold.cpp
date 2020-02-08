class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        vector<int>arr1;
        for(int i=0;i<arr.size();i++)
            arr1.push_back(arr[i]);
        int ans=0;
        for(int i=1;i<arr.size();i++)
        {
            arr1[i]+=arr1[i-1];
        }
        for(int i=k-1;i<arr1.size();i++)
        {
            int a;
            if(i-k<0)
            {
                a=arr1[i];
            }
            else
            {
                a=arr1[i]-arr1[i-k];
            }
            if(a/k>=threshold)
                ans++;
        }
        return ans;
    }
};