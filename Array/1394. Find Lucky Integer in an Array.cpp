class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int,int>m;
        for(int i=0;i<arr.size();i++)
            m[arr[i]]++;
        map<int,int> :: iterator itr;
        int ans = -1;
        for(itr=m.begin();itr!=m.end();itr++)
        {
            if(itr->first == itr->second)
                ans = itr->first;
                
        }
        return ans;
    }
};