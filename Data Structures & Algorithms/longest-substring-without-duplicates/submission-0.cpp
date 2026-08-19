class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_set<char> num_set;
        int l = 0, r = 0;
        int ans = 0;

        while (r < s.length()) {
            if (num_set.find(s[r]) == num_set.end()) {
                num_set.insert(s[r]);
                ans = max(ans, (int)num_set.size());
                r++;
            } else {
                num_set.erase(s[l]);
                l++;
            }
        }

        return ans;
    }
};