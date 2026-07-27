class Solution {
   public:
    bool isPalindrome(string s) {
        std::string str = "";

        for (char c : s) {
            if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
                str += c;
            } else if (c >= 'A' && c <= 'Z') {
                str += c + 32;
            }
        }

        if (str.length() == 0) {
            return true;
        }

        int left = 0;
        int right = str.length() - 1;

        while (left < right) {
            if (str[left] != str[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};
