class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        int diff=INT_MIN;
        int i=1;
        while(i<n){
            diff=max(diff, nums[i]-nums[i-1]);
            i++;
        }
        return max(0,diff);

        
    }
};