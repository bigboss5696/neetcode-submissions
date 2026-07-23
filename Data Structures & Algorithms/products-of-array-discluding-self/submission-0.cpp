class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> results(nums.size(), 0);

        int totalL = 1;
        for (int l = 0; l < nums.size(); ++l) {
            results[l] = totalL;
            totalL *= nums[l];
        }

        int totalR = 1;
        for (int r = nums.size() - 1; r >= 0; --r) {
            results[r] *= totalR;
            totalR *= nums[r];
        }

        return results;
    }
};
