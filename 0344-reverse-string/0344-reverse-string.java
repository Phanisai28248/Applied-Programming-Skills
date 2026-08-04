class Solution {
    public void reverseString(char[] s) {
        int left = 0;
        int right = s.length - 1;

        // Swap characters moving towards the center
        while (left < right) {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;

            left++;
            right--;
        }
    }
}