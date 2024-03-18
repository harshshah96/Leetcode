static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        sort(points.begin(), points.end());
        int count=0;
        vector<int> prev=points[0];
        
        for(int i=1; i<n; i++){
            if(points[i][0]>prev[1]){
                count++;
                prev=points[i];
            }else{ 
                prev[0]=max(prev[0],points[i][0]);
                prev[1]=min(prev[1],points[i][1]);
            }
        }
        return ++count;
    }
};