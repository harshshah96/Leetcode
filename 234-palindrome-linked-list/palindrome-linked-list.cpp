static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {

public:
    ListNode* reverseList(ListNode* head) {
// iterative solution
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* next=NULL;

        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL) return true;
        if(head->next->next==NULL){
            if(head->val==head->next->val) return true;
            else return false;
        }
        ListNode* fast=head;
        ListNode* slow=head;

        while((fast->next!=NULL) && (fast->next->next!=NULL) ){
            slow=(slow->next);
            fast=fast->next->next;
        }
        // slow is at middle

        ListNode* newHead=reverseList(slow->next);
        ListNode* a=head;
        ListNode* b=newHead;
        while(b!=NULL){
            if(a->val!=b->val) return false;
            a=a->next;
            b=b->next;
            
        }
        return true;

        
        
    }
};