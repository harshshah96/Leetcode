// 7 7 6 2 0 0 0 0 
// 0 1 2 3 4 5 6 7
static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(rbegin(nums),rend(nums));
        int n = size(nums);
        for(int i=0;i<n;i++){
            if(nums[i]>=(i+1) && (i==n-1 || nums[i+1]<i+1))  return i+1;
        }
        return -1;
    }
};