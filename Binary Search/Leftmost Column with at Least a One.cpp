/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &arr) {
        int ans = INT_MAX;
        for(int i = 0; i < arr.dimensions()[0]; i++)
        {
            int st = 0, en = arr.dimensions()[1]-1;
            while(st < en)
            {
                int mid = st+(en-st)/2;
                if(arr.get(i,mid) == 1)
                    en = mid;
                else
                    st = mid+1;
            }
            if(arr.get(i,st) == 0)
                continue;
            else
                ans = min(ans,st);
        }
        if(ans == INT_MAX)
            ans = -1;
        return ans;
    }
};