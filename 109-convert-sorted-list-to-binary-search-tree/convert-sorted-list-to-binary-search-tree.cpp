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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
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