/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode *temp=head;
        int n=0;
        while(temp)
        {
            temp=temp->next;
            n++;
        }
        int ans=0;
        while(head)
        {
            ans=ans+head->val*pow(2,n-1);
            n--;
            head=head->next;
        }
        return ans;
    }
};