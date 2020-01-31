class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>ans;
        int n=s.size();
        vector<int>arr1(26,-1);
        vector<int>arr2(26,-1);
        for(int i=0;i<n;i++)
        {
            int k=s[i]-'a';
            if(arr1[k]==-1)
                arr1[k]=i;
            arr2[k]=i;
        }
        vector<pair<int,int> >v;
        for(int i=0;i<26;i++)
        {
            if(arr1[i]!=-1)
                v.push_back(make_pair(arr1[i],arr2[i]));
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i].first<<" "<<v[i].second<<endl;
        }
        int i=0,j=0;
        int maxi=v[j].second;
        n=v.size();
        while(j<n)
        {
            maxi=max(maxi,v[j].second);
            while(j<n && maxi>=v[j].first){
                maxi=max(maxi,v[j].second);
                j++;
            }
            if(j<n)
            {
                ans.push_back(v[j].first-v[i].first);
            }
            if(j<n)
                i=j;
        }
        ans.push_back(maxi-v[i].first+1);
        return ans;
    }
};