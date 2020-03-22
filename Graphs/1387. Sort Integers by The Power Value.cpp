class Solution {
public:
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int> >v;
        for(int i =lo;i<=hi;i++)
        {
            queue<pair<int,int> >q;
            q.push(make_pair(i,0));
            while(!q.empty())
            {
                int fi = q.front().first;
                int se = q.front().second;
                q.pop();
                if(fi == 1)
                {
                    v.push_back(make_pair(se,i));
                    break;
                }
                if(fi%2)
                    q.push(make_pair(fi*3+1,se+1));
                else
                    q.push(make_pair(fi/2,se+1));
            }
        }
        sort(v.begin(),v.end());
        return v[k-1].second;
    }
};