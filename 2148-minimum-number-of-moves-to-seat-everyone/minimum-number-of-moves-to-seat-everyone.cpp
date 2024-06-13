static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());

        int ans = 0;

        for(int i = 0; i< seats.size() ; i++){
            ans += abs(seats[i]-students[i]);
        }

        return ans;
        
        
    }
};