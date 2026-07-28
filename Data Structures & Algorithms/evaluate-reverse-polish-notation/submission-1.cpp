class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> mStack;

        for (std::string s : tokens) {
            if (s != "+" && s != "-" && s != "*" && s != "/") {
                mStack.push(std::stoi(s));
                continue;
            }

            int num1 = mStack.top();
            mStack.pop();
            int num2 = mStack.top();
            mStack.pop();

            int sum = 0;
            if (s == "-") {
                sum = num2 - num1;
            } else if (s == "/") {
                sum = (num1 != 0) ? (num2 / num1) : 0;
            } else if (s == "*") {
                sum = num1 * num2;
            } else {
                sum = num1 + num2;
            }

            mStack.push(sum);
        }

        if (mStack.empty()) {
            return 0;
        }

        return mStack.top();
    }
};
