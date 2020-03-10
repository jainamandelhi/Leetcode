/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> &employees, int id) {
        int ans=0;
        set<int>s;
        map<int,int>m;
        vector<vector<int> >v(2002);
        for(int i=0;i<employees.size();i++)
        {
            m[employees[i]->id]=employees[i]->importance;
            for(int j=0;j<employees[i]->subordinates.size();j++)
            {
                v[employees[i]->id].push_back(employees[i]->subordinates[j]);            
            }
        }
        queue<int>q;
        q.push(id);
        while(!q.empty())
        {
            int a=q.front();
            ans+=m[a];
            q.pop();
            for(int i=0;i<v[a].size();i++)
            {
                q.push(v[a][i]);
            }
        }
        return ans;
    }
};