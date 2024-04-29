static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:

    int countOnes(int n){
        int ans=0;
        while(n>0){
            ans+= (n&1);
            n=n/2;
        }

        return ans;
    }
    int minOperations(vector<int>& nums, int k) {


        int ans=k;
        for(auto it : nums){
            ans^=it;
        }

        //count 1's

        int result=countOnes(ans);

        return result;
        
    }
};