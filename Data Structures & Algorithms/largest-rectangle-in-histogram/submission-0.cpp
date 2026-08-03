class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int max_area = 0;

        std::stack<int> st;

        for (int i = 0; i <= n; ++i) {
            int h = (i == n) ? 0 : heights[i];
            while (!st.empty() && h < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();

                int left = st.empty() ? -1 : st.top();
                int right = i;
                int width = right - left - 1;

                max_area = max(max_area, height * width);
            }
            st.push(i);
        }

        return max_area;
    }
};
