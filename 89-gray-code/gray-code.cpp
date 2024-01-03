class Solution {
public:
    vector<int> grayCode(int n) {
        
        vector<int> ans(1<<n);

        for (int i=0; i<(1<<n); i++) 
            // bitwise X-OR to find logically next grey code.
            ans[i] = i^(i>>1);
        return ans;
    }
};