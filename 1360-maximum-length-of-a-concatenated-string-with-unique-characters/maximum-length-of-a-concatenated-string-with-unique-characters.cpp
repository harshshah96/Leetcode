static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    bool hasDuplicates(string &temp, string &b){
        vector<int> check(26,0);
        for(int i=0; i<temp.length(); i++){
            if(check[temp[i]-'a']==0) check[temp[i]-'a'] ++;
            else return true; 
        }
        for(int i=0; i<b.length(); i++){
            if(check[b[i]-'a']==0) check[b[i]-'a'] ++;
            else return true; 
        }

        return false;
    }

    int solve(vector<string> &arr, int idx, string &temp){
        if(idx==arr.size()) return temp.length();
        string a=arr[idx];
        bool flag= hasDuplicates(a, temp);

        int include=INT_MIN;
        int exclude=INT_MIN;

        if(!flag){
            string b=temp;
            b+=a;
            include=solve(arr,idx+1, b);
        }
        exclude=solve(arr, idx+1, temp);

        return max(include,exclude);
        
        
    }

    int maxLength(vector<string>& arr) {
        int n=arr.size();

        string a="";
        return solve(arr,0,a);




        
    }
};