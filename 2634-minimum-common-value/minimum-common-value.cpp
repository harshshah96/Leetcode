static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        
        // // Suppose n1 is greater or equal to n2
        // // if not
        // if(n1<n2) return getCommon(nums2, nums1);

        int i=0;
        int j=0;

        while(i<n1 && j<n2){

            if(nums1[i]>nums2[j])j++;
            else if(nums1[i]<nums2[j])i++;
            else return nums1[i];

        }

        return -1;
    }
};