static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n=tickets.size();
        int ele=tickets[k];
        int ans=0;

        for(int i=0; i<n; i++){  
            if(i>k && tickets[i]>=tickets[k]) ans+=min(ele-1,tickets[i]);
            else ans+=min(ele,tickets[i]);
        }

        return ans;
    }
};