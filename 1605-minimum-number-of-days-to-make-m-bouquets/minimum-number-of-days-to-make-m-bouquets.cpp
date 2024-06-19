static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if ((long long)m * k > bloomDay.size()) return -1;

        int MaxDay = 0;

        for(int day : bloomDay){
            MaxDay = max(MaxDay, day);
        }
        
        int low = 0;
        int high = MaxDay;
        int ans = INT_MAX;
        bool isPossible = false;

        while(low<=high){
            int mid = low + (high - low)/2;
            int mTemp = m;
            int count = 0;

            for(int i = 0 ; i<n ; i++){
                if(bloomDay[i]<=mid) count++;
                else count = 0;

                if(count == k){
                    count = 0;
                    mTemp--;
                    if(mTemp == 0){
                        isPossible = true;
                        ans = min(ans,mid);
                        break;
                    } 
                }
            }

            if(mTemp == 0){
                high = mid-1;
            }else low = mid+1;

        }

        return isPossible ? ans : -1;



        
    }
};