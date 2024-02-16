import java.util.*;

class Solution {
    public int findLeastNumOfUniqueInts(int[] arr, int k) {
        Map<Integer, Integer> mp = new HashMap<>();
        for (int ele : arr) {
            mp.put(ele, mp.getOrDefault(ele, 0) + 1);
        }
        
        PriorityQueue<Map.Entry<Integer, Integer>> pq = new PriorityQueue<>(
            (a, b) -> Integer.compare(a.getValue(), b.getValue())
        );

        for (Map.Entry<Integer, Integer> entry : mp.entrySet()) {
            pq.offer(entry);
        }

        while (k > 0) {
            Map.Entry<Integer, Integer> entry = pq.poll();
            int freq = entry.getValue();
            if (k >= freq) {
                k -= freq;
            } else {
                pq.offer(entry); // Put back the element as we can't remove all occurrences
                break;
            }
        }

        return pq.size();
    }
}
