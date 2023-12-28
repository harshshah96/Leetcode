static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    int compress(vector<char>& chars) {
        string s="";
        int n=chars.size();
        if(n==1) return n;
        int i=0;
    
        while(i<n){
            int j=i;
            int count=1;
            while(j<n-1 and chars[j]==chars[j+1]){
                j++;
                count++;
            }
            s += chars[i];

            if(count>1) s += to_string(count);
            i = ++j;
        }
        for(int i=0; i<s.length(); i++){
            chars[i]=s[i];
        }
        return s.length();
    }
};