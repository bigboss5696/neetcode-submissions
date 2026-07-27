class Solution {
   public:
    int maxArea(vector<int>& heights) {
        if (heights.size() == 0) {
            return 0;
        }

        int left = 0;
        int right = heights.size() - 1;
        int max_area = 0;

        while (left < right) {
            int distant = right - left;
            int min = std::min(heights[left], heights[right]);
            int area = distant * min;
            if (area > max_area) {
                max_area = area;
            }

            if (heights[left] < heights[right]) {
                left++;
            } else {
                right--;
            }
        }

        return max_area;
    }
};
