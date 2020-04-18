class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<string>ans;
        ans.push_back("0");
        ans.push_back("1");
        for(int i = 2; i <= n; i++)
        {
            for(int j = ans.size()-1; j >= 0; j--)
                ans.push_back(ans[j]);
            for(int j = 0; j < ans.size()/2; j++)
                ans[j] = ans[j]+'0';
            for(int j = ans.size()/2; j < ans.size(); j++)
                ans[j] = ans[j]+'1';
        }
        vector<int>out;
        int index;
        for(int i = 0; i < ans.size(); i++)
        {
            string s = ans[i];
            int j = 0;
            int no = 0;
            while(s.size())
            {
                int k = s[s.size()-1]-'0';
                int l = 1<<j;
                no = no + k*l;
                j++;
                s.pop_back();
            }
            if(no == start)
                index = i;
            out.push_back(no);
        }
        vector<int>temp;
        while(temp.size() != pow(2,n))
        {
            int a = pow(2,n);
            temp.push_back(out[index%a]);
            index++;
        }
        return temp;
    }
};