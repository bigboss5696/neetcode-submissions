class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> counts;
        for (int num : nums) {
            counts[num]++;
        }
        std::vector<std::pair<int, int>> vec(counts.begin(), counts.end());
        if (k < vec.size()) {
            std::nth_element(
                vec.begin(), vec.begin() + k, vec.end(),
                [](const auto& a, const auto& b) { 
                    return a.second > b.second;
                }
            );
        }

        std::vector<int> results;
        results.reserve(k);
        for (int i = 0; i < std::min(k, (int)vec.size()); ++i) {
            results.push_back(vec[i].first);
        }

        return results;
    }
};