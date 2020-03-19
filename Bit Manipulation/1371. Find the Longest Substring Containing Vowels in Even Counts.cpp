class Solution {
public:
    int findTheLongestSubstring(string &s) {
        int mask = 0;
        int ans = 0;
        int arr[64];
        for(int i=0;i<64;i++)
            arr[i] = -1;
        int n = s.size();
        for(int i=0;i<n;i++)
        {
            int a = 0;
            if(s[i] == 'a')
                a = 1;
            else if(s[i] == 'e')
                a = 2;
            else if(s[i] == 'i')
                a = 3;
            else if(s[i] == 'o')
                a = 4;
            else if(s[i] == 'u')
                a = 5;
            if(a)
                mask = mask ^ (1<<a);
            if(arr[mask] == -1 && mask)
            {
                arr[mask] = i;
                continue;
            }
            else
            {
                ans = max(ans,i-arr[mask]);
            }
            
        }
        return ans;
    }
};