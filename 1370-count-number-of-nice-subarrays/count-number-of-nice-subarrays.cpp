class Solution {
public:
        int numberOfSubarrays(vector<int>& nums, int k) {
            // Mathematical intuition 
            // From set theory
            // exactly k = atmost (k) - atmost (k-1)
        return atMost(nums, k) - atMost(nums, k - 1);
    }

    int atMost(vector<int>& nums, int k) {

        int res = 0, i = 0, n = nums.size();
        
        for (int j = 0; j < n; j++) {

            if(nums[j]%2==1){
                k--;
            }
            while (k < 0){
                if(nums[i] % 2 ==1){
                    k++;
                }
                i++;

            }

            res += j - i + 1;
        }
        return res;
    }
};