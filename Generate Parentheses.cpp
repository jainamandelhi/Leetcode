vector<string>ans;
void func(int open,int close,string s)
{
    if(open==0 && close==0)
    {
        ans.push_back(s);
    }
    if(open-1>=0)
    {
        func(open-1,close,s+'(');
    }
    if(close-1>=0 && close-1>=open)
    {
        func(open,close-1,s+')');
    }
}
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        ans=vector<string>();
        func(n,n,"");
        return ans;
    }
};