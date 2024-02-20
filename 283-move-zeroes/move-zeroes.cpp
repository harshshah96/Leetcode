static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int i=0;// nums
        vector<int> ans(n);
        int j=0;
        int k=n-1;

        while(i<n){
            if(nums[i]==0){
                ans[k]=0;
                k--;
            }else{
                ans[j]=nums[i];
                j++;
            }
            i++;
        }

        nums=ans;
        
    }
};