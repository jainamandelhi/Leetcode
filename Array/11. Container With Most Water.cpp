class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxi=0,n=height.size();
        int i=0,j=n-1;
        while(i<j)
        {
            maxi=max(maxi,(j-i)*min(height[i],height[j]));
            if(height[j]<height[i])
                j--;
            else
                i++;
        }
        return maxi;
    }
};