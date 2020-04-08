class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int,int> >v;
        for(int i = 0; i < n; i++)
            v.push_back(make_pair(arr[i],i));
        sort(v.begin(),v.end());
        map<int,int>m;
        for(int i = 0; i < n; i++)
            m[arr[i]]++;
        int cnt = 0;
        map<int,int> :: iterator itr;
        for(itr = m.begin(); itr != m.end(); itr++)
        {
            cnt = cnt+(itr->second)/(itr->first);
        }
        vector<vector<int> >ans(cnt);
        int p = 0;
        int i = 0;
        while(i < n)
        {
            int t = v[i].first;
            for(int j = 0; j < t; j++)
            {
                ans[p].push_back(v[i].second);
                i++;
            }
            p++;
        }
        return ans;
    }
};