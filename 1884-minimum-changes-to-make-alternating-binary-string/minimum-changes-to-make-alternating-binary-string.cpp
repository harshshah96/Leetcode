static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();

class Solution {
public:
    int minOperations(string s){
    int answer = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if ((s[i] - '0') != i % 2){
                answer++;
            }
        }
        return min(answer, static_cast<int>(s.length() - answer));
    }

// private:
//      int count(string s, char pre){
//         int count=0;
//         int n=s.size();
//         for(int i=1; i<n; i++){
//             char curr=s[i];
//             if(pre==curr){
//                 count++;
//                 pre = (pre == '0'? '1' : '0');
//             }else{
//                 pre=curr;
//             }
//         }
//         return count;
//     }
};