static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.length();
        unordered_map<char, int> mp;
        vector<int> ans;

        for(auto ele:s){
            mp[ele]++;
        }
        int i=0;
        while(i<n){
            int j=i;
            unordered_map<char, int> mp1;
            bool flag=true;
            while(flag || (mp1.size()!=0 && j<n)){
                char ch = s[j];
                mp1[ch]++;
                if(mp1[ch]==mp[ch]) mp1.erase(ch);
                j++;
                flag=false;
            }
            ans.push_back(j-i);
            i=j;
        }

        return ans;


        
    }
};