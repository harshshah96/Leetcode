static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();

        int lo=0;
        int hi=n-1;

        while(hi>=lo){
            int mid=lo + (hi-lo)/2;
            if(lo==hi){
                if(nums[lo]<target)return lo+1;
                else return lo;
            }
            if(nums[mid]<target) lo=min(mid+1,hi);
            else if(nums[mid]==target) return mid;
            else{
                hi=max(mid-1,lo);
            }
        }

        return -1;        
    }
};