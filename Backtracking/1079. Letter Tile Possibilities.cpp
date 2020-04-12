class Solution {
public:
    int ans = 0;
    set<string>se;
    int fact(int n)
    {
        int val = 1;
        while(n > 0)
        {
            val = val*n;
            n--;
        }
        return val;
    }
    int cnt(string s)
    {
        int n = s.size();
        int temp = fact(n);
        unordered_map<int,int>m;
        for(int i = 0; i < n; i++)
            m[s[i]]++;
        unordered_map<int,int> :: iterator itr;
        for(itr = m.begin(); itr != m.end(); itr++)
            temp = temp/(fact(itr->second));
        return temp;
    }
    void per(string tiles,int i, int n,string s)
    {
        sort(s.begin(),s.end());
        if(se.find(s) == se.end() && s != "")
        {
            ans += cnt(s);
            se.insert(s);
        }
        if(i == n)
            return;
        per(tiles,i+1,n,s+tiles[i]);
        per(tiles,i+1,n,s);
    }
    int numTilePossibilities(string tiles) {
        int n = tiles.size();
        per(tiles,0,n,"");
        return ans;
    }
};