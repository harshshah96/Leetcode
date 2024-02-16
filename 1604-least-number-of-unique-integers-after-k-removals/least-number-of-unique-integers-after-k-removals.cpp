static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
       unordered_map<int,int> mp;
       for(int ele:arr){
           mp[ele]++;
       }
       priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

       for(auto ele:mp){
        //    int freq=ele.second;
        //    int num=ele.first;
           pq.push({ele.second, ele.first});
       }

       while(k){
           int freq=pq.top().first;
           if(k>=freq){
               k=k-freq;
               pq.pop();
           }else break;

       }

       return pq.size();

        
    }
};