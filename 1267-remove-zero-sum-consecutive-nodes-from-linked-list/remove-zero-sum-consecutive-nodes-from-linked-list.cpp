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
    ListNode* removeZeroSumSublists(ListNode* head) {
        vector<int>nums;
        ListNode* temp=head;
        while(temp){
            nums.push_back(temp->val);
            temp=temp->next;
        }
        int n=nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]==0)continue;
            int sum=nums[i];
            int j=i+1;
            while(sum!=0 && j<n){
                sum+=nums[j];
                j++;
            }
            while(sum==0 && i<j && i<n){
                nums[i]=0;
                if(i==j-1) break;
                else i++;
            }
        }
        // for(int i=0; i<n; i++){
        //     cout<<nums[i]<<" ";
        // }
        ListNode* temp1=new ListNode (-1);
        ListNode* ans=temp1;
        for(int i=0;i<n; i++){
            if(nums[i]!=0){
                ListNode* temp2=new ListNode(nums[i]);
                temp1->next=temp2;
                temp1=temp2;
            }
            
        }

        return ans->next;
        
    }
};