import java.util.PriorityQueue;

class Solution {
    public int furthestBuilding(int[] heights, int bricks, int ladders) 
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> b - a);
        // (a, b) -> b - a: This is a lambda expression that defines a custom comparator for the priority queue. It takes two Integer values a and b and returns the result of subtracting a from b. In other words, it defines a comparator that sorts elements in descending order (largest first).
        int bricksUsed = 0;
        int i = 0;
        for (; i < heights.length - 1; i++) {
            if (heights[i] >= heights[i + 1]) {
                continue;
            }
            int heightDiff = heights[i + 1] - heights[i];
            int bricksAvailable = bricks - bricksUsed;
            if (bricksAvailable >= heightDiff) {
                bricksUsed += heightDiff;
                pq.offer(heightDiff);
            } else if (ladders > 0) {
                if (!pq.isEmpty() && pq.peek() > heightDiff) {
                    bricksUsed -= pq.peek() - heightDiff;
                    pq.poll();
                    pq.offer(heightDiff);
                }
                ladders--;
            } else {
                break;
            }
        }
        return i;
    }
}
