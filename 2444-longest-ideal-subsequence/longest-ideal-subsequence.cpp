static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> t(26,0);
        int result=0;
        for(int i=0; i<s.length(); i++){

            int idx=s[i]-'a';
            int left=max(0, idx-k);
            int right=min(25,idx+k);

            int maxVal=0;
            for(int j=left; j<=right; j++){
                maxVal=max(maxVal, t[j]);
            }
            t[idx]= maxVal+1 ;
            result=max(result,t[idx]);
            cout<<t[idx]<<" ";
        }

        return result;
    }
};