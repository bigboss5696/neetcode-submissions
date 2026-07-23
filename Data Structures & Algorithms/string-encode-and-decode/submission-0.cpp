class Solution {
   public:
    string encode(vector<string>& strs) {
        std::string result;

        if (strs.size() <= 0) {
            return "";
        }

        for (std::string str : strs) {
            result += (std::to_string(str.length()) + "#" + str);
        }
        return result;
    }

    vector<string> decode(string s) {
        std::vector<std::string> results;
        int i = 0;
        while (i < s.length()) {
            int j = i;
            while (s[j] != '#') {
                j++;
            }

            int length = stoi(s.substr(i, j - i));
            results.push_back(s.substr(j + 1, length));
            i = j + 1 + length;
        }
        return results;
    }
};
