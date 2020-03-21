class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        int m1[N+1];
        int m2[N+1];
        memset(m1,0,sizeof(m1));
        memset(m2,0,sizeof(m2));
        for(int i=0;i<trust.size();i++)
        {
            int a = trust[i][0];
            int b = trust[i][1];
            m1[b]++;
            m2[a]++;
        }
        for(int i=1;i<=N;i++)
        {
            if(m1[i] == N-1 && m2[i] == 0)
                return i;
        }
        return -1;
    }
};