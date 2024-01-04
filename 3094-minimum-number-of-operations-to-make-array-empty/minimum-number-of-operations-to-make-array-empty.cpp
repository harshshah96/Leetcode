static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int ele: nums){
            mp[ele]++;

        }
        int ans=0;

        for(auto ele:mp){
            if(ele.second==1) return -1;
            else if(ele.second%3==0) ans+=ele.second/3;
            else if(ele.second%3==1){
                ans+= ((ele.second/3) -1) + (ele.second - ((ele.second/3) -1)*3)/2;
            }else if(ele.second%3==2) ans+=(ele.second/3 )+1;
        }

        return ans;
    }
};