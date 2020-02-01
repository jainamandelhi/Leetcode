class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        int n=forest.size();
        int m=forest[0].size();
        vector<tuple<int,int,int> >arr;
        if(forest[0][0]==0)
            return -1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(forest[i][j]>0)
                {
                    arr.push_back(make_tuple(forest[i][j],i,j));
                }
            }
        }
        arr.push_back(make_tuple(0,0,0));
        sort(arr.begin(),arr.end());
        int ans=0;
        for(int i=0;i<arr.size()-1;i++)
        {
            int srci=get<1>(arr[i]);
            int srcj=get<2>(arr[i]);
            int desi=get<1>(arr[i+1]);
            int desj=get<2>(arr[i+1]);
            vector<vector<int> >vis(n,vector<int>(m,INT_MAX));
            queue<tuple<int,int,int> >q;
            q.push(make_tuple(srci,srcj,0));
            int flag=0;
            while(!q.empty())
            {
                int a=get<0>(q.front());
                int b=get<1>(q.front());
                int c=get<2>(q.front());
                if(a==desi && b==desj)
                {
                    flag=1;
                    ans+=c;
                //cout<<c<<endl;
                    break;
                }
                vis[a][b]=1;
                q.pop();
                if(a+1<n && forest[a+1][b]!=0 && vis[a+1][b]==INT_MAX)
                {
                    vis[a+1][b]=1;
                    q.push(make_tuple(a+1,b,c+1));
                }
                if(a-1>=0 && forest[a-1][b]!=0 && vis[a-1][b]==INT_MAX)
                {
                    vis[a-1][b]=1;
                    q.push(make_tuple(a-1,b,c+1));
                }
                if(b+1<m && forest[a][b+1]!=0 && vis[a][b+1]==INT_MAX)
                {
                    vis[a][b+1]=1;
                    q.push(make_tuple(a,b+1,c+1));
                }
                if(b-1>=0 && forest[a][b-1]!=0 && vis[a][b-1]==INT_MAX)
                {
                    vis[a][b-1]=1;
                    q.push(make_tuple(a,b-1,c+1));
                }
            }
            if(flag==0)
                return -1;
        }
        return ans;
    }
};