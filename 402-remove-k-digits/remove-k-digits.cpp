static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    string removeKdigits(string num, int k) {


        if(k==num.length()) return "0";

        string a= num;
        int i=0; 
        string ans="";

        while(i<a.length() && k>0){
            if(i<a.length()-1 && a[i]>a[i+1]){
                string left=a.substr(0,i);
                string right=a.substr(i+1, a.length()-i-1);
                a="";
                a+=left;
                a+=right;
                i=0;
                k--;
            }else i++;
        }

        if(k>0){
            a=a.substr(0,a.length()-k);
        }
        

        i=0;
        while(i<a.length() && a[i]=='0'){
            if(i==a.length()-1) return "0";
            i++;

        }
        if(i>0) a=a.substr(i,a.length()-i);

        

        return a;
        
    }
};