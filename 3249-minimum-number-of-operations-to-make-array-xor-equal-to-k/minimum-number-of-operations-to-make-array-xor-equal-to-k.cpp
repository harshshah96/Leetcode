class Solution {
public:

    int countOnes(int n){
        int ans=0;
        while(n>0){
            ans+= (n&1);
            n=n>>1;
        }

        return ans;
    }
    int minOperations(vector<int>& nums, int k) {


        int ans=0;
        for(auto it : nums){
            ans^=it;
        }

        //count 1's

        int result=countOnes(ans^k);
        
        

        return result;
        
    }
};