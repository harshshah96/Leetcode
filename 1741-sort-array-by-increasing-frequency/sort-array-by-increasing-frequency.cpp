class Solution {
public:
    static vector<int> frequencySort(vector<int>& nums) {
        const int n = nums.size();
        vector<int> freq(201, 0);
        int maxF = 0, maxX = -1;
        for (int x : nums) {
            x += 100; // x-min_x where min_x=-100
            int f = ++freq[x];
            maxX = max(x, maxX);
            maxF = max(f, maxF);
        }
        vector<vector<int>> freqx(maxF + 1);
        for (int x = maxX; x >=0; x--) {
            if (freq[x] > 0)
                freqx[freq[x]].push_back(x-100); // Adjust value back
        }

        int i = 0;
        for (int f = 1; f <= maxF; f++) {
            auto& arr = freqx[f];
            for (int x : arr) {// each x occurs f times
                fill(nums.begin()+i, nums.begin()+i+f, x);
                i+=f;
            }
        }
        return nums;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();