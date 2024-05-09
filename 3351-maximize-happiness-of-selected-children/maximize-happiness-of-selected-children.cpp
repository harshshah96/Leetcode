static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n=happiness.size();
        long long sum = 0;
        sort(happiness.begin(), happiness.end(), greater<int>());
        for(int i = 0; i < k; i++) {
            happiness[i] = max(0, happiness[i]-i);
            sum += happiness[i];
        }
        return sum;
        
    }
};