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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *temp1=l1;
        ListNode *temp2=l2;
        ListNode *head=NULL;
        ListNode *tail=NULL;
        int carry=0;
        int a,b;
        while(temp1!=NULL || temp2!=NULL){
            if(temp1==NULL)
            {a=0;}
            else
            {a=temp1->val;}
            
            if(temp2==NULL)
            {b=0;}
            else
            {b=temp2->val;}
            int x=a+b+carry;        
            if(x > 9){
                carry=1;
            }
            else{
                carry=0;
            }
            x=x%10;
            ListNode *temp=new ListNode(x);
            if(head==NULL){
                head=tail=temp;
            }
            else{
                tail->next=temp;
                tail=tail->next;
            }
            if(temp1){temp1=temp1->next;}
            if(temp2){temp2=temp2->next;}
        }
        if(carry!=0){
            tail->next=new ListNode(1);
        }
        return head;
    }
};