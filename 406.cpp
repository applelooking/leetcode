class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        auto compare = [](const pair<int, int>& first, const pair<int, int>& second) {
            return first.first == second.first ? first.second < second.second : first.first > second.first;
        };
        sort(people.begin(), people.end(), compare);
        list<pair<int, int>> result;
        for (auto p : people) {
            auto it = result.begin();
            for (int i = 0;i < p.second;++i) {
                ++it;
            }
            result.insert(it, p);
        }
        vector<pair<int, int>> ret;
        for (auto it : result) {
            ret.push_back(it);
        }
        return ret;
    }
};