class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        set<double>s;
        for(int i = 0; i < coordinates.size(); i++)
        {
            for(int j = i+1; j < coordinates.size(); j++)
            {
                double temp = (coordinates[j][1] - coordinates[i][1]);
                double temp1 = (coordinates[j][0] - coordinates[i][0]);
                temp = temp/temp1;
                s.insert(temp);
            }
        }
        return s.size() == 1;
    }
};