static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        // Vector to store frequency of each character (26 characters in total for lowercase letters)
        vector<int> freq(26, INT_MAX);

        // Iterate over each word
        for (const string& word : words) {
            // Temporary vector to store frequency of characters in the current word
            vector<int> temp(26, 0);
            for (char c : word) {
                temp[c - 'a']++;
            }

            // Update the global frequency array with the minimum frequency
            for (int i = 0; i < 26; i++) {
                freq[i] = min(freq[i], temp[i]);
            }
        }

        // Prepare the result
        vector<string> result;
        for (int i = 0; i < 26; i++) {
            while (freq[i] > 0) {
                result.push_back(string(1, i + 'a'));
                freq[i]--;
            }
        }

        return result;
    }
};
