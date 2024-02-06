class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& str) {
        vector<vector<string>> ans; 
        unordered_map < string, vector<string> > m;
        for(string  x : str ){
            string s=x;
            sort(s.begin(),s.end());
            if(m.find(s)==m.end()){
                vector<string> v;
                v.push_back(x);
                m[s]=v;

            }else{
                m[s].push_back(x);
            }
        }
        for(auto x: m){
            ans.push_back(x.second);
        }
        return ans;
    }
};