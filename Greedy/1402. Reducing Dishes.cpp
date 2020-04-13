class Solution {
public:
    int maxSatisfaction(vector<int>& sat) {
        int sum = 0;
        int ans = 0;
        int maxi = 0;
        int n = sat.size();
        sort(sat.begin(),sat.end());
        for(int i = n-1; i >= 0; i--)
        {
            sum += sat[i];
            ans += sum;
            maxi = max(maxi,ans);
        }
        return maxi;
    }
};