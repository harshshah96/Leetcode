class Solution {
public:
    int minSteps(string s, string t) {
        int  n=s.length();

        unordered_map<char, int> mp;
        unordered_map<char, int> mp2;

        for(int i=0; i<n; i++){
            mp[s[i]]++;
            mp2[t[i]]++;
        }
        int ans=0;
        for(auto ele: mp){
            char a=ele.first;
            int freq= ele.second;
            if(mp2[a]<freq) ans+= (freq-mp2[a]);

        }

        return ans;


        
    }
};