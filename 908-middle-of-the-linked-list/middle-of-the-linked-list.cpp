 static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:

    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            fast=fast->next;
            if(fast->next)fast=fast->next;
            slow=slow->next;
        }

        return slow;

        
    }
};