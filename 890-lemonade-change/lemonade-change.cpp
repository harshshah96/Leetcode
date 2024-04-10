static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0;
        int ten=0;
        int twenty = 0;

        for(int i=0; i<bills.size() ; i++){
            if(bills[i]==5){
                five++;

            }else if(bills[i]==10){
                ten++;
                five--;
                if(five < 0) return false;

            }else{ // bills[i]==20
                if(ten==0){
                    five-=3;
                }else if(ten>0){
                    ten--;
                    five--;
                }
                if(ten<0) return false;
                if(five<0) return false;

            }
        }

        return true;
        
    }
};