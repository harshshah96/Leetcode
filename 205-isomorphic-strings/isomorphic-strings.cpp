static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // if(s.size()!=t.size())return false;
        vector<int>v (150,1000);

        for(int i=0; i<s.size(); i++){
            
            int ascii= (int)s[i];
            if(v[ascii]==1000){
                v[ascii]=s[i] - t[i];
            }else if(v[ascii]!= s[i] - t[i]){
                return false;
            }

        }
        for(int i=0; i<150; i++){
            v[i]=1000;
        }

        for(int i=0; i<s.size(); i++){
            
            int ascii= (int)t[i];
            if(v[ascii]==1000){
                v[ascii]=t[i] - s[i];
            }else if(v[ascii]!= t[i] - s[i]){
                return false;
                }

        }

        return true;
        
    }
};