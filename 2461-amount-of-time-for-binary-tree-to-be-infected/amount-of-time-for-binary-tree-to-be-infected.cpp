static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    TreeNode* temp=NULL;
    void markParent(TreeNode* root,unordered_map <TreeNode*,TreeNode*> &parent){
        if(root==NULL) return;
        if(root->left) parent[root->left]= root;
        if(root->right) parent[root->right]= root;
        markParent(root->left,parent);
        markParent(root->right,parent);
    }
    void find(TreeNode* root, int start){
        if(root==NULL) return;
        if(root->val==start){
            temp=root;
            return;
        }
        find(root->left, start);
        find(root->right, start);
    }


    int amountOfTime(TreeNode* root, int start) {
        find(root, start);
        TreeNode* a=temp;
        unordered_map <TreeNode*,TreeNode*> parent; // parent 
        markParent(root, parent); // parent marking of every TreeNode
        unordered_set <TreeNode*> s; //isInfected
        s.insert(a);
        queue<pair<TreeNode*, int>> q;
        q.push({a,0});

        //BFS
        int maxLevel=0;
        while(q.size()>0){

            pair <TreeNode*, int> p=q.front();
            q.pop();
            TreeNode* curr=p.first;
            int level= p.second;
            maxLevel= max(maxLevel, level);
            if(curr->left) {
                if(s.find(curr->left)==s.end()){ // not found in set i.e not infected yet.
                    q.push({curr->left, level+1});
                    s.insert(curr->left);
                }
            }
            if(curr->right) {
                if(s.find(curr->right)==s.end()){ // not found in set i.e not infected yet.
                    q.push({curr->right, level+1});
                    s.insert(curr->right);
                }
            }     
            if(parent.find(curr)!=parent.end()){ 
                if(s.find(parent[curr])==s.end()){ // not found in set i.e not infected yet.
                    q.push({parent[curr], level+1});
                    s.insert(parent[curr]);
                }
            }

        }
    parent.clear();
    s.clear();
    return maxLevel;
    }
};