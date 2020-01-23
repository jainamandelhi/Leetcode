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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *temp1=l1,*temp2=l2;
        if(!temp1 && !temp2)
            return temp1;
        if(!temp1)
            return temp2;
        if(!temp2)
            return temp1;
        int a;
        if(temp1->val<temp2->val)
        {
            a=temp1->val;
            temp1=temp1->next;
        }
        else
        {
            a=temp2->val;
            temp2=temp2->next;
        }
        ListNode *ans=new ListNode(a);
        ListNode *ans1=ans;
        while(temp1 && temp2)
        {
            if(temp1->val<temp2->val)
            {
                a=temp1->val;
                temp1=temp1->next;
            }
            else
            {
                a=temp2->val;
                temp2=temp2->next;
            }
            ListNode *temp=new ListNode(a);
            ans1->next=temp;
            ans1=ans1->next;
        }
        while(temp1)
        {
            a=temp1->val;
            ListNode *temp=new ListNode(a);
            ans1->next=temp;
            ans1=ans1->next;
            temp1=temp1->next;
        }
        while(temp2)
        {
            a=temp2->val;
            ListNode *temp=new ListNode(a);
            ans1->next=temp;
            ans1=ans1->next;
            temp2=temp2->next;
        }
        return ans;
    }
};