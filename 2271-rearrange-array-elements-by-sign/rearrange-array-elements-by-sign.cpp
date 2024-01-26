static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        // even index for +ve
        // odd index for -ve
        vector<int> temp(n);

        int i=0;
        int j=n/2;

        for(int k=0; k<n; k++){
            if(nums[k]>0){
                temp[i]=nums[k];
                i++;
            }else{
                temp[j]=nums[k];
                j++;
            }
            
        }
        i=0; 
        j=n/2;

        for(int k=0; k<n; k++){
            if(k%2==0){
                nums[k]=temp[i];
                i++;
            }else{
                nums[k]=temp[j];
                j++;
            }

        }

        return nums;
    }
};