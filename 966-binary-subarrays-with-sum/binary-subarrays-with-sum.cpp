static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:

    int atmostSumK(vector<int> nums, int goal){
        if(goal<0)
            return 0;
        int i = 0, n = nums.size(), count =0,sum=0;

        for(int j = 0;j<n;j++){
            sum+=nums[j];
            while(sum>goal){
                sum -=nums[i];
                i++;
            }
            count = count+(j-i+1);
        }
        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
       int k = atmostSumK(nums,goal) - atmostSumK(nums,goal-1);
        return k;
    }
};