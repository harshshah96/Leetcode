class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int j=0;j<=31;j++){
            int cnt=0;
            for(int i=0;i<n;i++){
                cnt+=((nums[i]>>j)&1);
            }
            if(cnt%3) ans|=(1<<j);
        }
        return ans;
    }
};