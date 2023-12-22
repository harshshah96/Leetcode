static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    bool isPalindromic(int num) {
        if (num < 0) return false;
        int reversed = 0, original = num;
        while (num != 0) {
            reversed = reversed * 10 + num % 10;
            num /= 10;
        }
        return original == reversed;
    }

    long long calculateCost(const vector<int>& nums, int target) {
        long long cost = 0;
        for (int num : nums) {
            cost += abs(num - target);
        }
        return cost;
    }
    
    int closestPalindromicSmall(int num) {
        if (isPalindromic(num)) {
            return num;
        }

        int smaller = num - 1;
        while (true) {
            if (isPalindromic(smaller)) {
                return smaller;
            }
            smaller--;
        }
}
int closestPalindromicLarge(int num) {
        if (isPalindromic(num)) {
            return num;
        }

        int larger = num + 1;
        while (true) {
            if (isPalindromic(larger)) {
                return larger;
            }
            larger++;
        }
}

    long long minimumCost(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(nullptr);
        cout.tie(nullptr);
        long long minCost = LLONG_MAX;
        int maxNum = *max_element(nums.begin(), nums.end());
        int minNum = *min_element(nums.begin(), nums.end());
        nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
        int medium = nums[nums.size() / 2];

        minCost = min(calculateCost(nums, closestPalindromicSmall(minNum)), minCost);
        minCost = min(calculateCost(nums, closestPalindromicLarge(maxNum)), minCost);
        minCost = min(calculateCost(nums, closestPalindromicSmall(medium)), minCost);
        minCost = min(calculateCost(nums, closestPalindromicLarge(medium)), minCost);

        return minCost;
    }
};