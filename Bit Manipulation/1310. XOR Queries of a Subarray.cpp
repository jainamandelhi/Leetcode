class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int t=0;
        int n=arr.size();
        for(int i=0;i<arr.size();i++)
            t^=arr[i];
        vector<int>arr1,arr2;
        arr1=arr;
        arr2=arr;
        for(int i=1;i<arr.size();i++)
            arr1[i]^=arr1[i-1];
        for(int i=n-2;i>=0;i--)
            arr2[i]^=arr2[i+1];
        vector<int>ans;
        for(int i=0;i<queries.size();i++)
        {
            int a,b;
            a=queries[i][0];
            b=queries[i][1];
            int c=t;
            if(a-1>=0)
                c^=arr1[a-1];
            if(b+1<arr.size())
                c^=arr2[b+1];
            ans.push_back(c);
        }
        return ans;
        
    }
};