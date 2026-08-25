import java.util.ArrayDeque;
import java.util.Deque;

class Solution {
    public int[] asteroidCollision(int[] asteroids) {
        Deque<Integer> stack = new ArrayDeque<>();
        
        for (int a : asteroids) {
            boolean destroyed = false;
            
            // Collision occurs only when stack top moves right (> 0) and current moves left (< 0)
            while (!stack.isEmpty() && stack.peekLast() > 0 && a < 0) {
                if (stack.peekLast() < Math.abs(a)) {
                    stack.pollLast(); // Destroy smaller right-moving asteroid and continue checking
                } else if (stack.peekLast() == Math.abs(a)) {
                    stack.pollLast(); // Destroy both equal-sized asteroids
                    destroyed = true;
                    break;
                } else {
                    destroyed = true; // Current asteroid is smaller and destroyed
                    break;
                }
            }
            
            if (!destroyed) {
                stack.addLast(a);
            }
        }
        
        // Convert stack to primitive array
        int[] result = new int[stack.size()];
        int i = 0;
        for (int val : stack) {
            result[i++] = val;
        }
        
        return result;
    }
}