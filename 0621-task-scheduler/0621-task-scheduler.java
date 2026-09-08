class Solution {
    public int leastInterval(char[] tasks, int n) {
        int[] freq = new int[26];
        int maxFreq = 0;

        // Count frequency of each task and find the maximum frequency
        for (char task : tasks) {
            freq[task - 'A']++;
            maxFreq = Math.max(maxFreq, freq[task - 'A']);
        }

        // Count how many tasks have the maximum frequency
        int maxFreqCount = 0;
        for (int count : freq) {
            if (count == maxFreq) {
                maxFreqCount++;
            }
        }

        // Calculate minimum slots based on max frequency frames
        int intervals = (maxFreq - 1) * (n + 1) + maxFreqCount;

        // Result is at least the total number of tasks
        return Math.max(tasks.length, intervals);
    }
}