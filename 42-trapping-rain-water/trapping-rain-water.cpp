static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    int trap(vector<int>& height) {

        int max=height[0];
        int n=height.size();
        int prev[n];

        prev[0]=-1;
        for(int i=1;i<n;i++){
        prev[i]=max;
        if(max<height[i]){
            max=height[i];
        }

    }

    prev[n-1]=-1;
    max=height[n-1];
    for(int i=n-2; i>=0; i--){
        if(max<prev[i] ) prev[i]=max;
        if(max<height[i]) max=height[i];
    }

    int volume=0;
for(int i=1; i<n-1;i++){
    if(prev[i]>height[i]) volume= volume +( prev[i]-height[i]);

}

return volume;

        
    }
};