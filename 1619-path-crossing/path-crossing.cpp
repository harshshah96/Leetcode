static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_set<string>st;
        int x = 0 , y = 0;
        st.insert(to_string(x) + "," + to_string(y));

        for(auto p:path)
        {
            if(p=='N') ++y;
            else if(p=='S')--y;
            else if(p=='E')++x;
            else --x;

            if(st.count(to_string(x)+","+to_string(y))) return true;
            st.insert(to_string(x) + "," + to_string(y));
            
        }
        return false;
        
    }
};