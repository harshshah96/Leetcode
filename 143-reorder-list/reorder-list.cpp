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
    
    void reorderList(ListNode* head) {
    //hints:
        //reverse the second half of linklist
        //partion both halves
        //now alternatively choose elements from both halves in new LL.4

        ListNode* fast=head;
        ListNode* slow=head;

        while((fast->next!=NULL) && (fast->next->next!=NULL) ){
            slow=(slow->next);
            fast=fast->next->next;
        }
        if(fast->next!=NULL) fast=fast->next;
        // slow is at (left) middle
        // reverse the LL after slow and part in two parts a & b
        ListNode* b=reverseList(slow->next);
        ListNode* a=head;
        slow->next=NULL;
        // create new LL
        ListNode* c=new ListNode(0); //farzi node
        ListNode* tc=c;

        //alternatively link elements from a and b;
        while(b && a){
            tc->next=a;
            tc=tc->next;
            a=a->next;
            tc->next=b;
            tc=tc->next;
            b=b->next;
            
        }
        if(b==NULL){
            tc->next=a;
        }else if(a==NULL){
            tc->next=b;
        }
        // bring head to new LL(one ahead coz of farzi Node)
        head=c->next;  
    }
};