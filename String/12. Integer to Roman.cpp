class Solution {
public:
    string intToRoman(int num) {
        string s="",s1="";
        int n=num,temp=0;
        while(n)
        {
            int a=n%10;
            n/=10;
            if(temp==0)
            {
                temp++;
                if(a==4)
                {
                    s+='I';
                    s+='V';
                    a-=4;
                }
                else if(a==9)
                {
                    s+='I';
                    s+='X';
                    a-=9;
                }
                else if(a>=5)
                {
                    s+='V';
                    a-=5;
                }
                while(a)
                {
                    s+='I';
                    a--;
                }
                reverse(s.begin(),s.end());
                s1+=s;
                s="";
            }
            else if(temp==1)
            {
                temp++;
                if(a==4)
                {
                    s+='X';
                    s+='L';
                    a-=4;
                }
                else if(a==9)
                {
                    s+='X';
                    s+='C';
                    a-=9;
                }
                else if(a>=5)
                {
                    s+='L';
                    a-=5;
                }
                while(a)
                {
                    s+='X';
                    a--;
                }
                reverse(s.begin(),s.end());
                s1+=s;
                s="";
            }
            else if(temp==2)
            {
                temp++;
                if(a==4)
                {
                    s+='C';
                    s+='D';
                    a-=4;
                }
                else if(a==9)
                {
                    s+='C';
                    s+='M';
                    a-=9;
                }
                else if(a>=5)
                {
                    s+='D';
                    a-=5;
                }
                while(a)
                {
                    s+='C';
                    a--;
                }
                reverse(s.begin(),s.end());
                s1+=s;
                s="";
            }
            else if(temp>2)
            {
                while(a>0)
                {
                    s+='M';
                    a--;
                }
                reverse(s.begin(),s.end());
                s1+=s;
                s="";
            }
            cout<<s1<<" ";
        }
        reverse(s1.begin(),s1.end());
        return s1;
    }
};