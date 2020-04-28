class FirstUnique {
public:
    unordered_map<int,int>m;
    int k = 0;
    vector<int>s;
    FirstUnique(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++)
        {
            if(m[nums[i]] == 0)
                s.push_back(nums[i]);
            m[nums[i]]++;
        }
    }
    int showFirstUnique() {
        while(k < s.size() && m[s[k]] > 1)
            k++;
        if(k < s.size())
            return s[k];
        return -1;
    }
    
    void add(int val) {
        if(m[val] == 0)
            s.push_back(val);
        m[val]++;
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */