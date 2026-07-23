class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.size() <= 1) {
            return {strs};
        }

        std::unordered_map<std::string, std::vector<std::string>> myMap;
        for (const auto& str: strs) {
            int count[26] = {0};
            for (char c: str) {
                count[c - 'a']++;
            }

            std::string key = "";
            for (int i = 0; i < 26; i++) {
                key += "#" + std::to_string(count[i]);
            }
            myMap[key].push_back(str);
        }

        std::vector<std::vector<std::string>> results;
        results.reserve(myMap.size());

        for (auto& [key, group] : myMap) {
            results.push_back(std::move(group));
        }

        return results;
    }
};
