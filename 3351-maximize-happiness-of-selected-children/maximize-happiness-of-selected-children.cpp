static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n=happiness.size();
        priority_queue<int> pq;

        long long ans=0;

        for(int i=0; i<n ; i++){
            pq.push(happiness[i]);
        }

        for(int i=0; i<k; i++){
            ans+=max(pq.top()-i,0);
            pq.pop();
        }

        return ans;
        
    }
};