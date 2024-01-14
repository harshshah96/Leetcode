static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    bool closeStrings(string str1, string str2) {
        if(str1.length()!=str2.length()) return false;
        int n=str1.length();
        unordered_map<char,int> a;
        unordered_map<char,int> b;
        

        for(int i=0;i<n;i++){
            a[str1[i]]++;
            b[str2[i]]++;
        }
        for(auto x : a){
            char ch= x.first;
            if(b.find(ch)==b.end())return false;
        }

        unordered_map<int,int> A;
        unordered_map<int,int> B;
        for(auto x: a){
            int s=x.second;
            A[s]++;
        }
        for(auto x: b){
            int s=x.second;
            B[s]++;
        }
        for( auto x: A){
            int key=x.first;
            if(B.find(key)==B.end())  return false;
            if(B[key]!=A[key])return false;
        }
        return true;

        
    }
};