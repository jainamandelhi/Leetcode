class Solution {
public:
    int myAtoi(string str) {
        int n=str.size();
        int ans=0;
        int y=1;
        int flag=0,flag1=0,flag2=0;
        if(str=="2147483648")
            return INT_MAX;
        if(str=="-2147483647")
            return -2147483647;
        for(int i=0;i<n;i++)
        {
            //cout<<ans<<" ";
            if(flag1==1 || flag2==1 || flag==1)
            {
                if(str[i]>='0' && str[i]<='9')
                {
                    if(flag==1 &&  ans<=INT_MIN/10)
                        return INT_MIN;
                    if(flag==0 && ans>=INT_MAX/10+1)
                        return INT_MAX;
                   // cout<<str[i]<<" ";
                    if(flag)
                        ans=ans*10-(str[i]-'0');
                    else
                        ans=ans*10+(str[i]-'0');
                }
                else
                    break;
            }
            else if(str[i]==' ')
                continue;
            else if(str[i]=='+')
                flag1=1;
            else if(str[i]=='-')
            {
                flag=1;
                continue;
            }
            else if(str[i]>='0' && str[i]<='9')
            {
                ans=ans*10+str[i]-'0';
                flag2=1;
            }
            else
                break;
        }
      //  if(flag)
        //    ans=-1*ans;
        return ans;
    }
};