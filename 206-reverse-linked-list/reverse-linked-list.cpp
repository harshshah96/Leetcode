static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        ListNode* a=head;
        ListNode* b = (a && a->next) ? a->next : NULL;
        if(!b) return head;
        ListNode* c= (b && b->next) ? b->next :  NULL;
        if(!c){
            b->next=a;
            a->next=NULL;
            return b;
        }
        
        if(a)a->next=NULL;
        while(c){
            b->next=a;
            a=b;
            b=c;
            c=c->next;
        } 
        if(b)b->next=a;

        return b;
        
    }
};