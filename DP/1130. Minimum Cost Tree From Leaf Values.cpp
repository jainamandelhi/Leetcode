class Solution {
public:
    #define ll int
    int mctFromLeafValues(vector<int>& arr) {
        int ans = 0;
        vector<int>temp = arr;
        sort(temp.begin(),temp.end());
        for(int i=0;i<temp.size();i++)
        {
            int a = temp[i];
            for(int j=0;j<arr.size();j++)
            {
                if(arr[j]==a)
                {
                    if(j==0)
                    {
                        if(arr.size()==1)
                            break;
                        ans = ans+arr[j]*arr[j+1];
                    }
                    else if(j==arr.size()-1)
                    {
                        if(arr.size()==1)
                            break;
                        ans = ans+arr[j]*arr[j-1];
                    }
                    else
                    {
                        ans = ans+arr[j]*min(arr[j-1],arr[j+1]);  
                    }
                    arr.erase(arr.begin()+j);
                }
            }
        }
        return ans;
    }
};