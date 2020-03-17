struct trie
{
    trie *left;
    trie *right;
};
int maxi = INT_MIN;
void insert(int n, trie *head)
{
    trie *temp = head;
    for(int i=31;i>=0;i--)
    {
        int a = n>>i;
        trie *node = new trie();
        if(a&1)
        {
            if(!temp->right)
                temp->right = node;
            temp = temp->right;
        }
        else
        {
            if(!temp->left)
                temp->left = node;
            temp = temp->left;
        }
    }
}

void search (int n,trie *head)
{
    trie *temp = head;
    int ans = 0;
    for(int i=31;i>=0;i--)
    {
        int a = n>>i;
        if(a&1)
        {
            if(temp->left)
            {
                temp =temp->left;
                ans =ans+pow(2,i);
            }
            else
                temp =temp->right;
        }
        else
        {
            if (temp->right)
            {
                temp = temp->right;
                ans = ans+pow(2,i);
            }
            else
                temp = temp->left;
        }
    }
    cout<<ans<<" ";
    maxi = max(maxi,ans);
}
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        trie *head = new trie();
        maxi = INT_MIN;
        int n = nums.size();
        for(int i=0;i<n;i++)
            insert(nums[i],head);
        for(int i=0;i<n;i++)
            search(nums[i],head);
        return maxi;
    }
};