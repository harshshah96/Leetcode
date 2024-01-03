static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int n=nums.size();
        vector<int> ans;
        int i=0;
        while(i<n){
            int j=i;
            while(j<n-1 && nums[j]==nums[j+1]) j++;
            int a=min(2,j-i+1);

            for(int k=0; k<a; k++){
                ans.push_back(nums[i]);
            }
            i=j+1;
        }

        n=ans.size();
        for(i=0; i<n; i++){
            nums[i]=ans[i];
        }

        return n;

        
    }
};