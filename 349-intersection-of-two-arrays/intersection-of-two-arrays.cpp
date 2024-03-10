static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // approach 1: using hash-sets
        unordered_set<int> set1;
        if(nums1.size()>nums2.size()) return intersection(nums2,nums1);
        for(int ele : nums1){
            set1.insert(ele);
        }
        vector<int>ans;
        for(int ele : nums2){
            if(set1.count(ele)){
                ans.push_back(ele);
                set1.erase(ele);

            }
        }
        return ans;



        
    }
};