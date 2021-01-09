class Solution {
public:
    int size(ListNode *temp){
        int k=0;
        while(temp){
            k++;
            temp=temp->next;
        }
        return k;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n1=size(headA),n2=size(headB);
        ListNode *tempA=headA;
        ListNode *tempB=headB;
        if(n1>n2){
            int k=0;
            while(k < n1-n2){
                tempA=tempA->next;
                k++;
            }
        }
        else if(n2>n1){
            int k=0;
            while(k<n2-n1){
                tempB=tempB->next;
                k++;
            }
        }
        while(tempA!=tempB){
            tempA=tempA->next;
            tempB=tempB->next;
        }
        return tempA;
    }
};