static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n=tokens.size();
        sort(tokens.begin(), tokens.end());

        int i=0;
        int j=n-1;

        int score=0;
        // int maxScore=0;

        while(i<=j){
            if(power>=tokens[i]){
                power-=tokens[i];
                score++;
                // maxScore=max(maxScore,score);
                i++;
            }else if(score && i!=j){
                power+=tokens[j];
                score--;
                j--;
            }else break;

        }

        return score;
        
    }
};