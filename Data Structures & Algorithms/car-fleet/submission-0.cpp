class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        if (n == 0) return 0;

        std::vector<pair<int, int>> cars(n);
        for (int i = 0; i < n; ++i) {
            cars[i] = {position[i], speed[i]};
        }

        std::sort(cars.begin(), cars.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 return a.first > b.first;
             });

        int count_fleet = 1;
        double prev_time = (target - cars[0].first) * 1.0 / cars[0].second;
        for (int i = 1; i < n; ++i) {
            double curr_time = (target - cars[i].first) * 1.0 / cars[i].second;
            if (curr_time > prev_time) {
                count_fleet++;
                prev_time = curr_time;
            }
        }

        return count_fleet;
    }
};
