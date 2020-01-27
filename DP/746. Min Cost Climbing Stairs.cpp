class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>arr(cost.size()+1);
        for(int i=1;i<=cost.size();i++)
        {
            if(i==1)
            {
                arr[i]=cost[i-1];
                continue;
            }
            arr[i]=min(arr[i-2]+cost[i-2],arr[i-1]+cost[i-1]);
        }
        vector<int>arr1(cost.size()+1);
        for(int i=2;i<=cost.size();i++)
        {
            if(i==2)
            {
                arr1[i]=cost[i-1];
                continue;
            }
            arr1[i]=min(arr1[i-2]+cost[i-2],arr1[i-1]+cost[i-1]);
        }
        return min(arr[cost.size()],arr1[cost.size()]);
    }
};