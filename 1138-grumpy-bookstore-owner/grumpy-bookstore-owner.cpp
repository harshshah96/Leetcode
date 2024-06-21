static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {\
        int n=customers.size();
        int k=minutes;
        int maxloss=0;
        int prevLoss=0;
        for(int i=0; i<k; i++){
           if(grumpy[i]==1) prevLoss += customers[i];
        }
        int maxLoss= prevLoss;
        int maxIdx=0;
        int i=1;
        int j=k;
        while(j<n){
            int currLoss= prevLoss + (grumpy[j]==1? customers[j] : 0 ) - (grumpy[i-1]==1? customers[i-1] : 0 );
            if(maxLoss<currLoss){
                maxLoss = currLoss;
                maxIdx = i;
            }
            prevLoss =  currLoss;
            i++;
            j++;
        }
        // filling 0s in the grumphy array window;
        for(int i=maxIdx ; i<maxIdx + k; i++){
            grumpy[i]=0;
        }
        // sum of satisfaction
        int sum=0;
        for(int i=0; i<n; i++){
            if(grumpy[i]==0){
                sum+=customers[i];
            }
        }

        return sum;


    }
};