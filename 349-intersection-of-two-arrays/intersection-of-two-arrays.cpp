static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1;
        unordered_set<int> set2;

        for(int ele : nums1){
            set1.insert(ele);
        }
        for(int ele : nums2){
            set2.insert(ele);
        }
        vector<int>ans;
        for(int ele : set1){
            if(set2.count(ele)) ans.push_back(ele);
        }
        return ans;
    }
};