class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> my_set(nums.begin(), nums.end());
        int max_len = 0;

        for (const int& num : my_set) {
            int count = 1;
            if (my_set.count(num - 1)) {
                continue;
            }

            int i = num;
            while (true) {
                if (!my_set.count(i + 1)) {
                    break;
                }

                count++;
                i++;
            }

            max_len = std::max(max_len, count);
        }

        return max_len;
    }
};
