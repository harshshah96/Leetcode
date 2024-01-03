static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n=bank.size();
        int m=bank[0].size();

        int pre_dev=0;
        // int curr_dev=0;
        int ans=0;

        for(int i=n-1; i>=0; i--){
            int count=0;
            for(int j=0; j<m; j++){
                if(bank[i][j]=='1') count++;
            }
            if(count>0){
                ans += pre_dev * count;
                pre_dev = count;
               
            }

        }

        return ans;
    }
};