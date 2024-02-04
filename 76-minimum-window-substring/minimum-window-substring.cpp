static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()<t.size()) return "";
        int n=s.size();
        
        unordered_map<char,int> mp;

        for(auto ch : t){
            mp[ch]++;
        }

        int minWindowSize=INT_MAX;
        int start_i=0;
        int requiredCount=t.length();

        int i=0;
        int j=0;

        while(j<n){
            char ch=s[j];
            if(mp[s[j]]>0) requiredCount--; 

            mp[s[j]]--;

            while(requiredCount==0){
                int len = j-i+1;
                if(minWindowSize>len){
                    minWindowSize=len;
                    start_i=i;
                }
                mp[s[i]]++;
                if(mp[s[i]]>0){
                    requiredCount++;
                }
                i++;
            }
            j++;
        }

        return minWindowSize == INT_MAX ? "" : s.substr(start_i,minWindowSize);
        
    }
};