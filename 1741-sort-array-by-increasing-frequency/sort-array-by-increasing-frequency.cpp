
class CustomComparator {
public:
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        if (a.second != b.second) {
            return a.second > b.second; // Min heap based on second value
        }
        return a.first < b.first; // Greater value of the first element in case of tie
    }
};

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mp; 

        for (auto ele : nums) {
            mp[ele]++;
        }

        // Priority queue with custom comparator
        priority_queue<pair<int, int>, vector<pair<int, int>>, CustomComparator> pq;

        for (auto ele : mp) {
            pq.push(ele);
        }

        vector<int> ans;

        while (!pq.empty()) {
            auto ele = pq.top();
            pq.pop();

            int freq = ele.second;
            int value = ele.first;

            for (int i = 0; i < freq; i++) {
                ans.push_back(value);
            }
        }

        return ans;
    }
};