static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    bool isPalindrome(int num) {
        int original = num;
        int reversed = 0;

        while (num > 0) {
            reversed = reversed * 10 + num % 10;
            num /= 10;
        }

        return original == reversed;
    }

    vector<int> nearestPalindromic(int num) {
        if(isPalindrome(num)) return {num};
        int smaller = num - 1;
        int larger = num + 1;
        int ansl=INT_MAX;
        int ansS=INT_MIN;
        
        while (true) {
            if (isPalindrome(larger)) {
                ansl=min(ansl,larger);

            }

            if (isPalindrome(smaller)) {
                ansS= max(ansS,smaller);
            }
            if(ansl!=INT_MAX && ansS!=INT_MIN) return{ansS,ansl};
            smaller--;
            larger++;
        }
        return {};
    }
    long long minimumCost(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> a=nearestPalindromic((n %2 )?nums[n/2]: (nums[n/2] + nums[n/2 - 1])/2);
        int x1=nearestPalindromic((n %2 )?nums[n/2]: (nums[n/2] + nums[n/2 - 1])/2)[0];
        int x2=a.size()>1?nearestPalindromic((n %2 )?nums[n/2]: (nums[n/2] + nums[n/2 - 1])/2)[1] : INT_MIN;

        long long int ans1=0;
        long long int ans2=0;

        for(int i=0; i<n; i++){
            ans1+=abs(nums[i]-x1);
        }
        if(x2!=INT_MIN){
            for(int i=0; i<n; i++){
            ans2+=abs(nums[i]-x2);
        }
        }else return ans1;
        

        return min(ans1,ans2);

        
        
        
    }
};