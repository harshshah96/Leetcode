static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        long long int prod = 1, ans = 0, n = nums.size();
        for(int i = 0, j = 0; j < n; j++){
            prod *= nums[j];
            while(i <= j and prod >= k) prod /= nums[i++];
            ans += j-i+1;
        }
        return ans;
    }
};