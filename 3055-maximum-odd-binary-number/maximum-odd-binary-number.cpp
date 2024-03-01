static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n=s.length();
        int count=0; // count one's

        for(int i=0; i<n; i++) if(s[i]=='1') count++;

        // string a(n,'0');
        s[n-1]='1';
        count--;
        for(int i=0; i<n-1; i++){
            if(count>=1){
                s[i]='1';
                count--;
            }else{
                s[i]='0';
            }
        }

        

        return s;
        
    }
};