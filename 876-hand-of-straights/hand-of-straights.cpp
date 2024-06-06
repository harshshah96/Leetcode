class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        sort(hand.begin(), hand.end()); // O(nlogn);
        int n = hand.size();
        if(n%groupSize != 0) return false; 

        map<int,int> mp;

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