class Solution {
    public boolean isPalindrome(ListNode head) {
        if (head == null || head.next == null) {
            return true;
        }

        // 1. Find the middle of the linked list using fast & slow pointers
        ListNode slow = head;
        ListNode fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        // 2. Reverse the second half of the list
        ListNode secondHalfHead = reverseList(slow);
        ListNode firstHalfHead = head;

        // 3. Compare the first and reversed second halves
        ListNode p2 = secondHalfHead;
        boolean result = true;
        while (result && p2 != null) {
            if (firstHalfHead.val != p2.val) {
                result = false;
            }
            firstHalfHead = firstHalfHead.next;
            p2 = p2.next;
        }

        // 4. Restore the original list structure (optional, but good practice)
        reverseList(secondHalfHead);

        return result;
    }

    private ListNode reverseList(ListNode head) {
        ListNode prev = null;
        ListNode curr = head;
        while (curr != null) {
            ListNode nextTemp = curr.next;
            curr.next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }
}