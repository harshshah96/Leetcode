// static int io_opt = []() {
//   ios::sync_with_stdio(false);
//   return 0;
// }();
class Solution {
public:
    string reversePrefix(string word, char ch) {
        string a="";
        int i;
        bool flag=false;
        for(i=0; i<word.length(); i++){
            a+=word[i];
            if(word[i]==ch) {
                flag=true;
                break;
            }
            
        } 
        if(flag){
            reverse(a.begin(),a.end());
            a+=word.substr(i+1,word.length()-(i+1));    
            return a;
        }
        return word;
        
    }
};