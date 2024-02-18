static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    typedef pair<long long, int> P;
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m=meetings.size();
        vector<int>roomCount(n,0);
        sort(meetings.begin(), meetings.end());
        priority_queue<int, vector<int>, greater<int>> isFree;
        priority_queue<P, vector<P>, greater<P>> endTime;

        for(int i=0; i<n; i++){
            isFree.push(i);
        }

        for(int i=0; i<m; i++){
            int start=meetings[i][0];
            int end=meetings[i][1];
            int diff=end-start;

            while(!endTime.empty() && endTime.top().first<= start){
                int room=endTime.top().second;
                endTime.pop();
                isFree.push(room);
            }

            if(!isFree.empty()){
                int roomAvailable=isFree.top();
                isFree.pop();
                endTime.push({end,roomAvailable});
                roomCount[roomAvailable]++;
                
            }else{  // we dont have any room available. Pick the earliest one
                int room= endTime.top().second;
                long long currEndTime = endTime.top().first;
                endTime.pop();
                endTime.push({currEndTime + diff, room});
                roomCount[room]++;
            }
        }
        int resultRoom=-1;
        int minCount=0;

        for(int i=0; i<n; i++){
            if(roomCount[i]>minCount){
                minCount=roomCount[i];
                resultRoom=i;
            } 
        }
        return resultRoom;
    }
};