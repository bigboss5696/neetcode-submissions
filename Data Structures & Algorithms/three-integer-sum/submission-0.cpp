class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<vector<int>> result = {};

        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i - 1] == nums[i]) {
                continue;
            }
            int target = nums[i];
            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int num = nums[left] + nums[right];
                if (num == -target) {
                    result.push_back({target, nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }

                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }

                    left++;
                    right--;
                } else if (num < -target) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        return result;
    }
};
