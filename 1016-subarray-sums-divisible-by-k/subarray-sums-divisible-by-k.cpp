static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0;
        vector<int> map(k,0);
        // memset(map, 0, sizeof(map));
        map[0] = 1;
        int sum = 0;
        for(auto& num : nums)
        {
            sum += num;
            int rem = (sum % k + k) % k;
            res += map[rem]++;
        }
        return res;

    }
};

