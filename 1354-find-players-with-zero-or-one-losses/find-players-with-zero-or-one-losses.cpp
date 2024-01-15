static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n=matches.size();
        unordered_map<int, int> mp;

        for(auto ele : matches){
            int win=ele[0];
            int lose=ele[1];

            if(mp[win]==0){
                mp[win]=-1;

            }
            if(mp[lose]>=0 ){
                mp[lose]++;
            } else mp[lose]=1;
        }

        vector<int>ans0;
        vector<int>ans1;

        for(auto ele: mp){
            if(ele.second==-1) ans0.push_back(ele.first);
            else if(ele.second==1) ans1.push_back(ele.first);
        }
        
        sort(ans0.begin(),ans0.end());
        sort(ans1.begin(),ans1.end());

        return {ans0,ans1};
    }
};