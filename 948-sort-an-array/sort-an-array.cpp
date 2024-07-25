int BUCKETS[100001];

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int OFFSET = 50000;
        memset(BUCKETS, 0, sizeof(BUCKETS)); 
        int minOffset=INT_MAX;
        int maxOffset=INT_MIN;
        
        for (auto n : nums) {
            BUCKETS[n+OFFSET]++;
            minOffset=min(minOffset,n+OFFSET);
            maxOffset=max(maxOffset,n+OFFSET);
        }
        int j = 0;
        for (int i = minOffset; i <=maxOffset; i++) {
            for (int k = 0; k < BUCKETS[i]; k++) {
                nums[j] = (i-OFFSET);
                j++;
            }
        }
        return nums;
    }
};