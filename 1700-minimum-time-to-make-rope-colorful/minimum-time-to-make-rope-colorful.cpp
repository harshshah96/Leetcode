class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n=colors.length();
        if(n==1) return 0;
        int i=0; 
        // int j=0;
        int ans=0;
        
        while(i<n){
            int j=i;
            while(j<n && colors[j]==colors[j+1]) j++;
            int sum=0;
            int max_ele=INT_MIN;
            for(int k=i; k<=j; k++){    
                sum+=neededTime[k];
                if(max_ele<neededTime[k]){
                    max_ele=neededTime[k];
                }
            }
            ans+=sum-max_ele;
            i=j+1;
        }

        return ans;
        
    }
};