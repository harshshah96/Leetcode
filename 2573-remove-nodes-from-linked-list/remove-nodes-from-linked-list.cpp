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
 static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        ListNode* temp=head;
        stack<ListNode*> st;

        while(temp!=NULL){
            int a=temp->val;
            if(st.empty()) st.push(temp);
            else{
                while(!st.empty() && st.top()->val < a)st.pop();
                st.push(temp);
            }
            temp=temp->next;
        }

        while(!st.empty()){

            ListNode* Node1=st.top();
            st.pop();
            if(st.empty()) return Node1;
            ListNode* Node2 =  st.top();
            st.pop();

            Node2->next = Node1;
            st.push(Node2);
        }

        return NULL;

        
    }
};