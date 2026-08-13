#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class TimeMap {
   public:
    unordered_map<string, vector<pair<int, string>>> mp;

    TimeMap() {}

    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        if (!mp.contains(key)) {
            return "";
        }

        const auto& vals = mp[key];

        int left = 0;
        int right = vals.size() - 1;
        string ans = "";

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (vals[mid].first <= timestamp) {
                ans = vals[mid].second;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return ans;
    }
};