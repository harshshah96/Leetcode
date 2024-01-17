static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    TreeNode* helper(vector<int>& nums, int lo, int hi){
        if(lo>hi) return NULL;
        int mid = lo + (hi-lo)/2;
        TreeNode* root= new TreeNode(nums[mid]);
        root->left = helper(nums,lo,mid-1);
        root->right =helper(nums,mid+1,hi);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
       vector<int> nums;
       ListNode* a=head;
       
       while(a){
           nums.push_back(a->val);
           a=a->next;
       }

        int n = nums.size();
        return helper(nums , 0, n-1);
    }

};