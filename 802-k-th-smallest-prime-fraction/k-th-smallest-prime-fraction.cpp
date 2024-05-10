static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
#define pp pair<double, pair<int,int>>
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue <pp> pq;
        for(int i=0;i<arr.size(); i++){
            for(int j=i+1;j<arr.size(); j++){
                double x=(arr[i]/(arr[j]*1.0));
                if(pq.size()==k){
                    if(x < pq.top().first){
                        pq.pop();
                        pq.push({x,{arr[i],arr[j]}});
                    }
                    
                }else{
                    pq.push({x,{arr[i],arr[j]}});
                }
                
            }
        }
        return{pq.top().second.first,pq.top().second.second};
        
    }
};