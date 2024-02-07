static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
#define pp pair<int, char>
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(int i=0; i<s.size(); i++){
            mp[s[i]]++;
        }
        priority_queue <pp> pq;

        for(auto  ele: mp){
            pq.push({ele.second,ele.first});
        }

        pp curr;
        string ans="";

        while(mp.size()>0){
            curr=pq.top();
            pq.pop();
            while(curr.first--){
                ans.push_back(curr.second);
            }
            mp.erase(curr.second);
        }
        return ans;
        
    }
};