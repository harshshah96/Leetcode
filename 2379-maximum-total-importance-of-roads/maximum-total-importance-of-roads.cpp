static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
    unordered_map<int, int> freq;

    for (auto &ele : roads) {
        freq[ele[0]]++;
        freq[ele[1]]++;
    }

    priority_queue<int> pq;

    for (auto &ele : freq) {
        pq.push(ele.second);
    }

    long long ans = 0;

    while (!pq.empty() && n > 0) {
        ans += static_cast<long long>(n) * pq.top();
        pq.pop();
        n--;
    }

    return ans;      
}

};