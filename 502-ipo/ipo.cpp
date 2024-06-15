static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {

        int n = profits.size();

        vector<pair<int,int>> arr(n);

        for(int i=0; i<n ; i++){
            arr[i] = {capital[i],profits[i]};
        }

        sort(arr.begin(), arr.end());

        int i = 0; 

        priority_queue <int> pq;

        while(k--){

            while(i<n && arr[i].first <= w){
                // can buy
                pq.push(arr[i].second);
                i++;
            }
            if(pq.empty()) break;
            w+=pq.top();
            pq.pop();
        }

        return w;
    }
};