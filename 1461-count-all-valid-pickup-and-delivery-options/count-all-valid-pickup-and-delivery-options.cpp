static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    int countOrders(int n) {

        if(n==1) return 1;

        long long int result=1;
        
        for(int i=2; i<=n; i++){
            int spaces=(i-1)*2 + 1;
            int possibility= spaces *(spaces  +1)/2;
            result *= possibility;
            result%=1000000007;
        }

        return result;
        
    }
};