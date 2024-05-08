static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n= score.size();

        vector<string> ans(n);

        priority_queue < pair < int , int > >  pq;

        for(int i=0; i< n; i++){
            pq.push({score[i],i});
        }

        for(int i = 0 ; i < n ; i++){
            int a = pq.top().first;
            int idx = pq.top().second;
            pq.pop();
            if(i<=2){
                if(i==0) ans[idx] = "Gold Medal";
                else if(i==1) ans[idx] = "Silver Medal";
                if(i==2) ans[idx] = "Bronze Medal";
            }else{
                ans[idx]=to_string( i + 1);
            }
        }

        return ans;
        
    }
};