typedef long long ll;
static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    long long wonderfulSubstrings(string word) {
        int n=word.length();

        unordered_map<ll, ll> mp;
        mp[0]=1;

        int cum_xor=0;
        ll  result=0;
        for(int i=0; i<n; i++){

            cum_xor ^= (1 << (word[i]-'a'));

            result += mp[cum_xor];

            for(int j=0 ; j<10 ; j++){
                int c = cum_xor ^ ( 1 << j ) ;
                result+=mp[c];
            }
        
            mp[cum_xor]++;
        }

        return result;
    }
};