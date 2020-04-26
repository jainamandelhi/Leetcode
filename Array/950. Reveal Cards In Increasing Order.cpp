class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());
        int n = deck.size();
        vector<int>temp(n);
        for(int i = 0; i < n; i++)
            temp[i] = i;
        vector<int>ans(n);
        int i = 0,j= 0;
        while(temp.size())
        {
            ans[temp[i]] = deck[j];
            j++;
            temp.erase(temp.begin()+i);
            if(!temp.size())
                break;
            i %= temp.size();
            i++;
            i %= temp.size();
        }
        return ans;
    }
};