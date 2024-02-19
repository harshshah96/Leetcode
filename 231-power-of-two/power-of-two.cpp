static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==1) return true;
        if(n%2!=0) return false;
        int count=0;
        while(n>0){
            count+=(n&1);
            n=n>>1;
        }

        return (count==1);

    }
};