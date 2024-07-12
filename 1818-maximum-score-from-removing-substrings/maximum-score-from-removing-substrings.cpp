#include <iostream>
#include <stack>
#include <string>
using namespace std;

static int io_opt = []() {
    ios::sync_with_stdio(false);
    return 0;
}();

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        // Helper function to calculate the score for given pairs
        auto calculateScore = [](string &str, char first, char second, int score) {
            stack<char> st;
            int points = 0;
            for (char c : str) {
                if (!st.empty() && c == second && st.top() == first) {
                    st.pop();
                    points += score;
                } else {
                    st.push(c);
                }
            }
            
            // Reconstruct the remaining string after removal
            string remaining;
            while (!st.empty()) {
                remaining.push_back(st.top());
                st.pop();
            }
            reverse(remaining.begin(), remaining.end());
            return make_pair(points, remaining);
        };

        int totalScore = 0;

        // If x > y, prioritize "ab" pairs first, else prioritize "ba" pairs
        if (x >= y) {
            auto result = calculateScore(s, 'a', 'b', x);
            totalScore += result.first;
            s = result.second;
            result = calculateScore(s, 'b', 'a', y);
            totalScore += result.first;
        } else {
            auto result = calculateScore(s, 'b', 'a', y);
            totalScore += result.first;
            s = result.second;
            result = calculateScore(s, 'a', 'b', x);
            totalScore += result.first;
        }

        return totalScore;
    }
};
