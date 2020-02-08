class Solution {
public:
    string decodeString(string s) {
        int n = s.size();
        int i=0;
        string ans="";
        stack<string>st;
        while(i<n)
        {
            if(s[i]!=']')
            {
                string s1="";
                s1.push_back(s[i]);
                st.push(s1);
            }
            else
            {
                stack<string>st1;
                while((st.top()>="a" && st.top()<="z") || (st.top()>="A" && st.top()<="Z"))
                {
                    st1.push(st.top());
                    st.pop();
                }
                st.pop();
                string str1="";
                while(!st1.empty())
                {
                    str1+=st1.top();
                    st1.pop();
                }
                int num=0;
                stack<string>st2;
                while(!st.empty() && st.top()>="0" && st.top()<="9")
                {
                    st2.push(st.top());
                    st.pop();
                }
                while(!st2.empty())
                {
                    num=num*10+(st2.top()[0]-'0');
                    st2.pop();
                }
                string str2="";
                for(int i=0;i<num;i++)
                    str2+=str1;
                if(st.empty())
                    ans+=str2;
                else
                    st.push(str2);
            }
            i++;
        }
        stack<string>st1;
        while(!st.empty())
        {
            st1.push(st.top());
            st.pop();
        }
        while(!st1.empty())
        {
            ans+=st1.top();
            st1.pop();
        }
        return ans;
    }
};