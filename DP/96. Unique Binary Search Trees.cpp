class Solution {
public:
    int numTrees(int n) {
        int arr[n+1];
        arr[0] = 1;
        arr[1] = 1;
        for(int i = 2;i <= n;i++)
        {
            int j = i-1;
            arr[i] = 0;
            while(j >= 0)
            {
                arr[i] = arr[i]+arr[j]*arr[i-1-j--];
            }
        }
        return arr[n];
    }
};