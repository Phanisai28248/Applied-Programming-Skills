#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Min-heap to store top k largest elements
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int num : nums) {
            minHeap.push(num);
            // Maintain heap size of k
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        // Top element is the kth largest element
        return minHeap.top();
    }
};