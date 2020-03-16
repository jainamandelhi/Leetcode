
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int> >v;
        for(int i=0;i<speed.size();i++)
        {
            v.push_back(make_pair(efficiency[i],speed[i]));
        }
        sort(v.begin(),v.end(),greater<pair<int,int> >());
        for(int i=0;i<speed.size();i++)
            swap(v[i].first,v[i].second);
        priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >p;
        long long ans=0,temp=0;
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i].first<<" "<<v[i].second<<endl;
        }
        for(int i=0;i<v.size();i++)
        {
            if(p.size()==k)
            {
                temp-=p.top().first;
                p.pop();
            }
            temp+=v[i].first;
            p.push(v[i]);
            ans=max(ans,temp*v[i].second);
        }
        return ans%1000000007;
    }
};