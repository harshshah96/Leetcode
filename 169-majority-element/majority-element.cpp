static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    int majorityElement(vector<int>& nums) {

        // int n=nums.size();
        sort(nums.begin(),nums.end());
        
        return nums[(nums.size())/2];

        
    }
};