class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        std::vector<int> result(n);

        std::stack<int> mStack;

        // 30,38,30,36,35,40,28
        for (int i = 0; i < n; ++i) {
            while (!mStack.empty() && temperatures[i] > temperatures[mStack.top()]) {
                int prev_day = mStack.top();
                result[prev_day] = i - prev_day;
                mStack.pop();
            }

            mStack.push(i);
        }

        return result;
    }
};
