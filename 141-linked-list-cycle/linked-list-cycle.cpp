static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast= head;
        ListNode* slow= head;
        while(fast!=NULL && fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next->next;
            if(slow==fast) return true;
        }
        return false;
        
    }
};