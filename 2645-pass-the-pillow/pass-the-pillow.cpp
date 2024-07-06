static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    int passThePillow(int n, int time) {

        bool forward = (time/(n-1))%2 == 0 ? true : false;

        int steps = (time%(n-1));

        if(forward) return steps + 1;
        return n-steps;

        
    }
};