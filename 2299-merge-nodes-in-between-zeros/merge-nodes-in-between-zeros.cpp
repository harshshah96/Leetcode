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
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp=head->next;
        ListNode* Node=new ListNode(-1);
        ListNode* dummy=Node;

        while(temp){
            int sum=0;
            while(temp->val!=0 && temp){
                sum+=temp->val;
                temp=temp->next;
            }
            ListNode* a=new ListNode(sum);
            dummy->next=a;
            dummy=dummy->next;
            temp=temp->next;
        }
        return Node->next;
        
    }
};