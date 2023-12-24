static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        char ini=s[0];
        int c1 = count(s,ini);
        int c2= count(s, ini =='0'? '1':'0');
        c2++;

        return min(c1,c2);
    }
private:
     int count(string s, char pre){
        int count=0;
        int n=s.size();
        for(int i=1; i<n; i++){
            char curr=s[i];
            if(pre==curr){
                count++;
                pre = (pre == '0'? '1' : '0');
            }else{
                pre=curr;
            }
        }
        return count;
    }
};