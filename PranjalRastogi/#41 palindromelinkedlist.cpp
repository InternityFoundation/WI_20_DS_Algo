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
        class HOH
        {
        public:
  ListNode * head;

    HOH(ListNode * head){
        this->head=head;
    }
};

bool checkPalin(HOH* h, ListNode* head)
{
    if(head==NULL)
    {
        return true;
    }
    
    bool ans=checkPalin(h, head->next);
    
    if(ans==false)
    {
        return false;
    }
    else
    {
        if(h->head->val==head->val)
        {
            h->head=h->head->next;
            return true;
        }
        else
        {
            return false;
        }
    }
}
    bool isPalindrome(ListNode* head) 
    {
            HOH* h=new HOH(head);
            bool ans=checkPalin(h, head);
            return ans;        
    }
};
