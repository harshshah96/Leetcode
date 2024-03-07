 static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:

    ListNode* middleNode(ListNode* head) {
        int count =0;
        ListNode* temp=head;
        while(temp!=NULL){
            temp=temp->next;
            count++;
        }
        int middle=count/2;
        for(int i=1; i<=middle;i++){
            head=head->next;
        }
        return head;

        
    }
};