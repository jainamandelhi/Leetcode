class Solution {
public:
    bool isValid(string s) {
        int n=s.size();
        stack<char>st;
        st.push('.');
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
                st.push(s[i]);
            else if(s[i]==')')
            {
                if(st.top()!='(')
                    return 0;
                st.pop();
            }
            else if(s[i]=='{')
                st.push(s[i]);
            else if(s[i]=='}')
            {
                if(st.top()!='{')
                    return 0;
                st.pop();
            }
            else if(s[i]=='[')
                st.push(s[i]);
            else if(s[i]==']')
            {
                if(st.top()!='[')
                    return 0;
                st.pop();
            }
        }
        
        if(st.size()>1)
            return 0;
        return 1;
    }
};