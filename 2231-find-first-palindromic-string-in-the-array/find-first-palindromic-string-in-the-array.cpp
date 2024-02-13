class Solution {
public:
    bool isPalindrome(string &a){
        int n=a.length();
        int i=0;
        while(i<=n/2){
            if(a[i]!=a[n-i-1]) return false;
            i++;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
    
        for(int i=0; i<words.size(); ++i) if(isPalindrome(words[i])) return words[i];

        return "";
        
    }
};