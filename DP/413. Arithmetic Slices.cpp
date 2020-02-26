#define ll int 
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        ll n=A.size();
        ll ans=0,temp=0;
        for(ll i=2;i<n;i++)
        {
            if(A[i]-A[i-1]==A[i-1]-A[i-2])
            {
                if(temp==0)
                {
                    ans++;
                    temp=ans;
                }
                else
                {
                    ans+=temp+1;
                    temp++;
                }
            }
            else
                temp=0;
        }
        return ans;
    }
};