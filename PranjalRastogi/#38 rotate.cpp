/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(head==NULL) return NULL;
        ListNode *cur=head;
        int len=1;
        while(cur->next!=NULL){
            cur=cur->next;
            len++;
        }
        cur->next=head;
        int preLen=len-k%len-1;
        ListNode *pre=head;
        while(preLen--)
            pre=pre->next;
        head=pre->next;
        pre->next=NULL;
        return head;
    }
};
