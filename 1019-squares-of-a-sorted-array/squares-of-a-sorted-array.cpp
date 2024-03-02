static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return{nums[0]*nums[0]};
        vector<int>ans; 
        int j=0;

        while( j<n && nums[j]<0 )j++;
        int i = max(j-1,0);
        if(i==j){
            i=-1;
        }

        while(i>=0 && j<n ){
            if(abs(nums[i])<=abs(nums[j])){
                ans.push_back(nums[i]*nums[i]);
                i--;
            }else{
                ans.push_back(nums[j]*nums[j]);
                j++;
            }
        }

        while(i<0 && j<n){
            ans.push_back(nums[j]*nums[j]);
            j++;
        }
        while(j>=n && i>=0){
            ans.push_back(nums[i]*nums[i]);
            i--; 
        }
        return ans;
    }
};