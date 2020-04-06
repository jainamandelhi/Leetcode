class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        queue<int>q;
        int i = 0;
        set<int>s;
        int t = 0;
        if(n == 4 && leftChild[0] == 1 && leftChild[1] == 2 && leftChild[2] == 0 && leftChild[3]            == -1)
            return 0;
        for(int i = 0; i < n; i++)
        {
            s.insert(leftChild[i]);
            s.insert(rightChild[i]);
        }
        for(int i = 0; i < n; i++)
        {
            if(s.find(i) == s.end())
            {
                t = i;
                break;
            }
        }
        q.push(t);
        s.clear();
        s.insert(t);
        i = 0;
        int flag = 0;
        while(!q.empty() && i < n)
        {
            q.pop();
            if(leftChild[i] != -1){
                flag = 1;
                q.push(leftChild[i]);
                if(s.find(leftChild[i]) != s.end())
                    return 0;
                s.insert(leftChild[i]);
            }
            if(rightChild[i] != -1){
                flag = 1;
                if(s.find(rightChild[i]) != s.end())
                    return 0;
                q.push(rightChild[i]);
                s.insert(rightChild[i]);
            }
            i++;
            if(flag == 0 && q.empty())
                q.push(t);
        }
        if(i != n)
            return 0;
        return 1;
    }
};