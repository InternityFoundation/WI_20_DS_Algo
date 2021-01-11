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
    ListNode* deleteDuplicates(ListNode* head)
    {
 
    ListNode *temp=head;
    
     if (temp == NULL)  
    	return head; 
    
    while(head->next!=NULL)
    {
        if((head->val)==(head->next->val))
        {
            ListNode *del=head->next;
            head->next=del->next;
            delete del;
        }
        else
        head=head->next;
    }
    
    return temp;
    }
};
