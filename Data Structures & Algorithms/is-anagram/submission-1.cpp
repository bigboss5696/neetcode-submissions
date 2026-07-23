class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        std::vector<int> countS(26, 0);
        std::vector<int> countT(26, 0);

        for (int i = 0; i < s.size(); i++) {
            countS[s[i] - 'a']++;
        }

        for (int j = 0; j < t.size(); j++) {
            countT[t[j] - 'a']++;
        }

        return countS == countT;
    }
};
