static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    bool halvesAreAlike(string s) {
        int n=s.length(); // max 1000;
        // length is always even
        
        int count1=0;

        for(int i=0; i<n/2; i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
                s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' ||
                s[i] == 'O' || s[i] == 'U' ) count1++;
            if(s[i+n/2] == 'a' || s[i+n/2] == 'e' || s[i+n/2] == 'i' || s[i+n/2] == 'o' ||
                s[i+n/2] == 'u' || s[i+n/2] == 'A' || s[i+n/2] == 'E' || s[i+n/2] == 'I' ||
                s[i+n/2] == 'O' || s[i+n/2] == 'U' ) count1--;


        }
    return count1==0;
        
    }
};