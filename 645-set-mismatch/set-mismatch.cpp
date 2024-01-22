static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {        
        int n=nums.size();
        vector<int> a;
        int i=0;
        while(i<n){
            int correctIdx=nums[i]-1;
            if(nums[i]==i+1 || nums[i]==nums[correctIdx])i++;
            else swap(nums[i],nums[correctIdx]);
        }
        for(int i=0; i<n; i++){
            if(nums[i]!= i+1){ 
                a.push_back(nums[i]);
                a.push_back(i+1);

                }
        }

        return a;
        
    }
};