static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> count(26);
        for (auto& w : words) {
            for (auto& c : w) {
                ++count[c - 'a'];
            }
        }
        return all_of(cbegin(count), cend(count),
                      [&words](int c) {
                          return c % size(words) == 0;
                      });
    }
};
