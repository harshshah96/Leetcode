 static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* temp1= list1;
        // ListNode* temp1B= list1;
        ListNode* temp2= list2;

        while(temp2->next!=NULL){
            temp2=temp2->next;    
        }
        for(int i=0; i<=b; i++){
            temp1=temp1->next;
        }
        temp2->next=temp1;
        
        temp1=list1;
        temp2=list2;
        for(int i=0; i<a-1;i++){
            temp1=temp1->next;
        }
        temp1->next=temp2;

        return list1;

        
    }
};

 