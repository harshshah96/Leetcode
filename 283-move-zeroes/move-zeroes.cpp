static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j;
        while(i<n){
            while(i<n && nums[i]!=0) i++;
            j=i+1;
            while(j<n && nums[j]==0) j++;
            if(i<n && j<n){
                int temp=nums[i];
                nums[i]=nums[j];
                nums[j]=temp;
            }
            i++;
        }
    }
};