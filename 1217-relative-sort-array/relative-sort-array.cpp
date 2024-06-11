class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n=arr1.size();
        unordered_map<int, int> mp;

        for(int i=0; i<n;i++){
            mp[arr1[i]]++;
        }
        vector<int> ans;
        for(int i=0; i<arr2.size();i++){
            int freq=mp[arr2[i]];
            mp.erase(arr2[i]);
            while(freq>0){
                ans.push_back(arr2[i]);
                freq--;
            }
        }
        n=ans.size();
        for(auto x: mp){
            while(x.second>0){
                ans.push_back(x.first);
                x.second--;
            }
        }
        sort(ans.begin()+(n),ans.end());
        return ans;

        
    }
};