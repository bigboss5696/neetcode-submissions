class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> mySet(nums.size());

        for (int num : nums) {
            mySet.insert(num);
        }

        return mySet.size() != nums.size();
    }
};
