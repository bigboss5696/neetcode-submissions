class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> results;
        std:unordered_map<int, int> myMap;
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            auto it = myMap.find(complement);
            if (it != myMap.end()) {
                return { it->second, i };
            }

            myMap[nums[i]] = i;
        }

        return {};
    }
};