static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {

         int n = nums.size();

        if (k == 1) return true;
        if(n % k) return false;

        sort(nums.begin(), nums.end()); // O(nlogn);

        map<int,int> mp; // OrderedMap -> TC = O(logn)

        for(auto ele : nums){
            mp[ele]++;
        }
        // int a = n/k + 1;

        while(!mp.empty()){
            int curr = mp.begin()->first;
            for(int i=0; i<k ; i++){
                if(mp[curr+i] == 0) return false;
                mp[curr + i]--;
                if(mp[curr + i] <=0) mp.erase(curr + i);
            }
        }
        return true;
        
    }
};