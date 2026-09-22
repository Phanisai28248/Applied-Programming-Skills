#include <vector>
#include <queue>
#include <tuple>

using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result;
        if (nums1.empty() || nums2.empty() || k == 0) return result;

        // Min-heap storing {sum, i, j}
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> minHeap;

        // Push initial pairs (nums1[i], nums2[0]) for the first min(k, nums1.size()) elements
        for (int i = 0; i < min((int)nums1.size(), k); ++i) {
            minHeap.push({nums1[i] + nums2[0], i, 0});
        }

        // Extract the smallest element up to k times
        while (!minHeap.empty() && result.size() < k) {
            auto [sum, i, j] = minHeap.top();
            minHeap.pop();

            result.push_back({nums1[i], nums2[j]});

            // If there's a next element in nums2 for nums1[i], push it to minHeap
            if (j + 1 < nums2.size()) {
                minHeap.push({nums1[i] + nums2[j + 1], i, j + 1});
            }
        }

        return result;
    }
};