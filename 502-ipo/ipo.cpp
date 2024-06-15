static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
bool CustomComparator(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.first == b.first) {
        return a.second > b.second;  // If the first elements are the same, compare the second elements in descending order
    }
    return a.first < b.first;  // Ascending order for the first element
}
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {

        int n = profits.size();

        vector<pair<int,int>> arr(n);

        for(int i=0; i<n ; i++){
            arr[i] = {capital[i],profits[i]};
        }

        sort(arr.begin(), arr.end(), CustomComparator);

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