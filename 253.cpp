/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int, int> mapping;
        for (auto& interval : intervals) {
            mapping[interval.start]++;
            mapping[interval.end]--;
        }
        int result = 0;
        int current = 0;
        for (auto& it : mapping) {
            current += it.second;
            result = max(result, current);
        }
        return result;
    }
};