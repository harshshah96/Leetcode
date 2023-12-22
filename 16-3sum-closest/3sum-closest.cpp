class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int res = 16384;
        int best_end = n - 1;
        int i, val, left, right;
        bool flag;
        sort(nums.begin(), nums.end());

        //edge cases(2)
        if(nums[0] + nums[1] + nums[2] >= target)
            return nums[0] + nums[1] + nums[2];
        
        if(nums[n - 1] + nums[n - 2] + nums[n - 3] <= target)
            return nums[n - 1] + nums[n - 2] + nums[n - 3];
        

        for(i = 0; i < n - 2; ++i) {
            nums[i] = nums[i];

            if(i > 0 && nums[i] == nums[i - 1])
                continue;

            left = i + 1;
            flag = true;
            right = best_end;

            while (left < right) {
                val = nums[i] + nums[left] + nums[right];
                
                val > target ? (right -= 1, best_end -= flag) : (left += 1, flag = false);

                if(abs(target - val) < abs(target - res))
                    res = val;
            }

            if(target == res)
                return target;
        }

        return res;
    }
};
