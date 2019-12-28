class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows<2)
            return s;
        int temp=2*(numRows-2)+2,temp1=0;
        string s1="";
        int n=s.size();
        int flag=0;
        for(int i=0;i<n;i++)
        {
            int flag1=0;
            int j=i,add=temp;
            while(j<n)
            {
                s1+=s[j];
                j+=add;
                if(temp1==0)
                    continue;
                if(flag1==0)
                {
                    flag1=1;
                    j-=temp1;
                }
                else
                {
                    flag1=0;
                    j=j-(temp-temp1);
                }
            }
            if(flag==1)
                break;
            temp1+=2;
            if(temp1==temp){
                temp1=0;
                flag=1;
            }
        }
        return s1;
    }
};