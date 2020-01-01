class Solution {
public:
    int romanToInt(string s) {
        int ans=0;
        int n=s.size();
       for(int i=n-1;i>=0;i--)
       {
           if(s[i]=='I')
               ans++;
           if(s[i]=='V')
           {
               if(i-1>=0 && s[i-1]=='I')
               {
                   ans+=4;
                   i--;
               }
               else
               {
                   ans+=5;
               }
           }
           if(s[i]=='X')
           {
               if(i-1>=0 && s[i-1]=='I')
               {
                   ans+=9;
                   i--;
               }
               else
               {
                   ans+=10;
               }
           }
           if(s[i]=='L')
           {
               if(i-1>=0 && s[i-1]=='X')
               {
                   ans+=40;
                   i--;
               }
               else
               {
                   ans+=50;
               }
           }
           if(s[i]=='C')
           {
               if(i-1>=0 && s[i-1]=='X')
               {
                   ans+=90;
                   i--;
               }
               else
               {
                   ans+=100;
               }
           }
           if(s[i]=='D')
           {
               if(i-1>=0 && s[i-1]=='C')
               {
                   ans+=400;
                   i--;
               }
               else
               {
                   ans+=500;
               }
           }
           if(s[i]=='M')
           {
               if(i-1>=0 && s[i-1]=='C')
               {
                   ans+=900;
                   i--;
               }
               else
               {
                   ans+=1000;
               }
           }
       }
        return ans;
    }
};