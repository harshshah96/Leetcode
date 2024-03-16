class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        int length=0;
        unordered_map<int,int> mp; // sum , idx
        mp[0]=-1;
        int sum=0;

        for(int i=0;i<n ;i++){
            sum += nums[i]==0 ? -1 : 1;
            if(mp.find(sum)!=mp.end()) length=max(length , i-mp[sum]);
            else{
                mp[sum]=i;
            }

        }

        return length;
        
    }
};