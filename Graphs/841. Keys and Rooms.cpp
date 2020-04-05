class Solution {
public:
    bool f(vector<vector<int> >&rooms,int &cnt,int p,int i,vector<int>&vis)
    {
        if(cnt == p)
            return true;
        bool a = false;
        for(int j = 0; j<rooms[i].size(); j++)
        {
            if(vis[rooms[i][j]])
                continue;
            vis[rooms[i][j]] = 1;
            cnt++;
            a = a || f(rooms,cnt,p,rooms[i][j],vis);
        }
        return a;
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int p = rooms.size();
        vector<int>vis(p+1);
        vis[0] = 1;
        int temp = 1;
        return f(rooms,temp,p,0,vis);
    }
};