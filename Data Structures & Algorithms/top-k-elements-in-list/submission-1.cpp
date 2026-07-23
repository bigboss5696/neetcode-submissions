class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        std::unordered_map<int, int> counts;
        std::vector<int> result;

        for (int num : nums) {
            counts[num]++;
        }

        std::vector<std::vector<int>> buckets(n + 1);
        for (const auto& [num, freq] : counts) {
            buckets[freq].push_back(num);
        }

        for (int i = n; i > 0 && result.size() < k; --i) {
            if (!buckets[i].empty()) {
                for (int num : buckets[i]) {
                    result.push_back(num);
                }
                if (result.size() == k) break;
            }
        }

        return result;
    }
};
