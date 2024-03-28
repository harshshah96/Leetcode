
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> frequencyMap;
        int left = 0, maxLength = INT_MIN;

    for (int right = 0; right < nums.size(); right++) {
        frequencyMap[nums[right]]++;
        while(frequencyMap[nums[right]] > k) {
            frequencyMap[nums[left]]--;
            if (frequencyMap[nums[left]] == 0) {
                frequencyMap.erase(nums[left]);
            }
            left++;
        }
        maxLength = max(maxLength, right - left + 1);
    }
        
    return (maxLength == INT_MIN) ? 0 : maxLength;
    }
};