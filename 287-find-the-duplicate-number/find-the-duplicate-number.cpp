static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        while(1){
            // this is an infinite loop i.e it will iterrate until we get our answere.
            // Mentioned in the problem constraints that unique answer exist for every testCase.
            int correctIdx= nums[0];
            if(nums[nums[0]]==nums[0]) return nums[0];
            else swap(nums[0],nums[correctIdx]);
        }
        return -1;
    }


};