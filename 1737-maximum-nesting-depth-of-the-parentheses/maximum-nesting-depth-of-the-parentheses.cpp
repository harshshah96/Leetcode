static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    int maxDepth(string s) {
        int depth=0;
        int maxDepth=0;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='(') depth +=1;
            else if(s[i]== ')') depth-=1;
            else continue;
            maxDepth=max(maxDepth,depth);
        }

        return maxDepth;
    }
};