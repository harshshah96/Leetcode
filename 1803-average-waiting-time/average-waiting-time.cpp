static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution{
    public:
        double averageWaitingTime( vector <vector<int>> & customers){
            double totalWaitingTime = 0;
            int currentTime = 0;

            for(const auto& customer : customers){
                int arrival = customer[0];
                int service = customer [1];
                if(currentTime < arrival)  currentTime = arrival;

                int waitingTime = currentTime - arrival + service;
                totalWaitingTime += waitingTime;
                currentTime +=service;
            }

            return (double)(totalWaitingTime / customers.size());

        }
};


// class Solution {
// public:
//     double averageWaitingTime(vector<vector<int>>& customers) {
//         double total_waiting_time = 0;
//         int current_time = 0;

//         for (const auto& customer : customers) {
//             int arrival = customer[0];
//             int service = customer[1];
//             if (current_time < arrival) {
//                 current_time = arrival;
//             }
//             int waiting_time = current_time - arrival + service;
//             total_waiting_time += waiting_time;
//             current_time += service;
//         }

//         return total_waiting_time / customers.size();
//     }
// };