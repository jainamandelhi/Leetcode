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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt=0;
        ListNode* temp=head;
        while(temp)
        {
            cnt++;
            temp=temp->next;
        }
        if(n==cnt)
            return head->next;
        cnt=cnt-n-1;
        temp=head;
        while(cnt--)
           temp=temp->next;
        temp->next=temp->next->next;
        return head;
    }
};