class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int n=arr1.size();
        vector<int>a(n);
        vector<int>b(n);
        vector<int>c(n);
        vector<int>d(n);
        for(int i=0;i<n;i++)
        {
            a[i]=arr1[i]+arr2[i]+i;
            b[i]=arr1[i]+arr2[i]-i;
            c[i]=arr1[i]-arr2[i]+i;
            d[i]=arr1[i]-arr2[i]-i;
            
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        sort(c.begin(),c.end());
        sort(d.begin(),d.end());
        return(max(a[n-1]-a[0],max(b[n-1]-b[0],max(c[n-1]-c[0],d[n-1]-d[0]))));
    }
};