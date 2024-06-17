static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();

class Solution {
public:
    bool isPerfectSquare(int n){
        int a=sqrt(n);
        if(a*a==n) return true;
        else return false;
    }
    bool judgeSquareSum(int c) {
        int x=0;
        int y=c;
        while(x<=y){
        if(isPerfectSquare(x) && isPerfectSquare(y)){
            return true;
        }else if(!isPerfectSquare(y)){
            y=((int)sqrt(y))*((int)sqrt(y));
            x=c-y;
        }else{// if x is not a perfect square.
            x=((int)(sqrt(x)+1))*((int)(sqrt(x)+1));
            y=c-x;
        }
        }
        return false;
    }
};