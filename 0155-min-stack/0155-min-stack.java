import java.util.ArrayDeque;
import java.util.Deque;

class MinStack {
    private Deque<Long> stack;
    private long min;

    public MinStack() {
        stack = new ArrayDeque<>();
    }
    
    public void push(int val) {
        if (stack.isEmpty()) {
            stack.push(0L);
            min = val;
        } else {
            // Store the difference between val and min
            stack.push((long) val - min);
            if (val < min) {
                min = val; // Update min
            }
        }
    }
    
    public void pop() {
        if (stack.isEmpty()) return;
        
        long diff = stack.pop();
        // If diff < 0, the popped element was the minimum, restore previous min
        if (diff < 0) {
            min = min - diff;
        }
    }
    
    public int top() {
        long diff = stack.peek();
        if (diff < 0) {
            return (int) min;
        } else {
            return (int) (min + diff);
        }
    }
    
    public int getMin() {
        return (int) min;
    }
}