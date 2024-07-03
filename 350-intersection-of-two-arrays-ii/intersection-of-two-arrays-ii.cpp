static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();
        int m = nums2.size();

        unordered_map<int,int> freq1;
        unordered_map<int,int> freq2;
        vector <int> ans;

        for(int i = 0 ; i<n ; i++){
            freq1[nums1[i]]++;
        }
        for(int i = 0 ; i<m ; i++){
            freq2[nums2[i]]++;
        }

        for(auto ele : freq1){
            if(freq2[ele.first]>0){
                int freq = min(freq1[ele.first],freq2[ele.first]);
                for(int i=0; i< freq; i++){
                    ans.push_back(ele.first);
                }
            }
        }

        return ans;
        
    }
};