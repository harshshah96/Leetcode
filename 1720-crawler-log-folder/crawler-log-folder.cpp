static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    int minOperations(vector<string>& logs) {
        int n = logs.size();

        
        int operations = 0;
        

        for(int i = 0 ; i<n ; i++){
            string operation = logs[i];
            if(operation.length() == 3 && operation == "../"){
                if(operations>0)operations--;
                // cout<<i<<" "<<operation.substr(operation.length() - 1 - 3,3)<<endl;
            }else if( operation.length() == 2 && operation == "./"){
                // nothing
                // cout<<i<<" " <<operation.substr(operation.length() - 1 - 2,2)<<endl;
            }else operations++;

        }

        return operations;
        
    }
};