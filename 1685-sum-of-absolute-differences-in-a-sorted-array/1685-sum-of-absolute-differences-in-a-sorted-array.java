class Solution {
    public int[] getSumAbsoluteDifferences(int[] nums) {
        int n = nums.length;
        int[] result = new int[n];  
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }
        int leftSum = 0;
        int rightSum = totalSum;
        for (int i = 0; i < n; i++) {
            // Subtract current element from right sum
            rightSum -= nums[i];
            int leftCount = i;
            int rightCount = n - 1 - i;
            // Formula for absolute differences using sorted property:
            // (nums[i] * leftCount - leftSum) + (rightSum - nums[i] * rightCount)
            int leftTotal = nums[i] * leftCount - leftSum;
            int rightTotal = rightSum - nums[i] * rightCount;
            result[i] = leftTotal + rightTotal;
            // Add current element to left sum for next iteration
            leftSum += nums[i];
        }
        return result;
    }
}