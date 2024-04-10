static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    long long countSubstrings(string s, char c) {
        int n=s.length();
        long long int count=0;

        for(int i=0; i<n; i++){
            if(s[i]==c) count++; 
        }

        return (count*(count+1))/2;
        
    }
};