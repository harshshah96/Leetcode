static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        int n = hand.size();

        if (groupSize == 1) return true;
        if(n % groupSize) return false;

        sort(hand.begin(), hand.end()); // O(nlogn);

        map<int,int> mp; // OrderedMap -> TC = O(logn)

        for(auto ele : hand){
            mp[ele]++;
        }
        // int a = n/groupSize + 1;

        while(!mp.empty()){
            int curr = mp.begin()->first;
            for(int i=0; i<groupSize ; i++){
                if(mp[curr+i] == 0) return false;
                mp[curr + i]--;
                if(mp[curr + i] <=0) mp.erase(curr + i);
            }
        }
        return true;
    }
};