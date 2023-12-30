static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char,int>mp;
        int n=words.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<words[i].size(); j++){
                mp[words[i][j]]++;
            }
        }
        for(auto ele:mp){
            if(ele.second % n !=0) return false;
        }

        return true;

        
    }
};