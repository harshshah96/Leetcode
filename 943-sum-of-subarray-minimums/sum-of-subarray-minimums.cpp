#define MOD 1000000007

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n), right(n);

        stack<int> s;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[i] < arr[s.top()]) {
                s.pop();
            }
            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        while (!s.empty()) s.pop(); // Clear the stack

        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[i] <= arr[s.top()]) {
                s.pop();
            }
            right[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        long long int sum = 0; 
        for (int i = 0; i < n; ++i) {
            sum += static_cast<long long int>(i - left[i]) * (right[i] - i) * arr[i] % MOD;
            sum %= MOD;
        }

        return sum;
    }
};
