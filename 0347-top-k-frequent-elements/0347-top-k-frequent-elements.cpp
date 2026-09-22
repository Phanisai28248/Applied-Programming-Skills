#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Step 1: Count frequencies of each element
        unordered_map<int, int> freqMap;
        for (int num : nums) {
            freqMap[num]++;
        }

        // Step 2: Group elements by frequency using buckets
        // Maximum frequency an element can have is nums.size()
        vector<vector<int>> buckets(nums.size() + 1);
        for (auto& [num, count] : freqMap) {
            buckets[count].push_back(num);
        }

        // Step 3: Gather top k frequent elements from highest frequency to lowest
        vector<int> result;
        for (int i = buckets.size() - 1; i >= 0 && result.size() < k; --i) {
            for (int num : buckets[i]) {
                result.push_back(num);
                if (result.size() == k) {
                    break;
                }
            }
        }

        return result;
    }
};