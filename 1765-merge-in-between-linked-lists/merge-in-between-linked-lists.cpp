 static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {

        ListNode* slow=list1;
        int diff = b-a+1;

        ListNode* fast=list1;

        while(diff--){
            fast=fast->next;
        }
        for(int i=0; i<a-1; i++){
            slow=slow->next;
            fast=fast->next;
        }

        ListNode* end = list2;
        while(end->next){
            end=end->next;
        }
        end->next=fast->next;
        slow->next=list2;

        return list1;


        
    }
};