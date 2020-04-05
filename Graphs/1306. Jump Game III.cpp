class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        set<int>s;
        queue<int>q;
        q.push(start);
        while(!q.empty())
        {
            start = q.front();
            s.insert(start);
            q.pop();
            cout<<start<<endl;
            if(start-arr[start] >= 0 && s.find(start-arr[start]) == s.end())
                q.push(start-arr[start]);
            if(start+arr[start] < arr.size() && s.find(start+arr[start]) == s.end())
                q.push(start+arr[start]);
            s.insert(start-arr[start]);
            s.insert(start+arr[start]);
            if(arr[start] == 0)
                return 1;
        }
        return 0;
    }
};