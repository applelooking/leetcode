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
    static bool compare(const Interval& first, const Interval& second) {
        return first.start < second.start ? true : first.start == second.start ? first.end < second.end : false;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        vector<Interval> result;
        if (intervals.empty()) return result;
        Interval cur = intervals[0];
        for (auto interval : intervals) {
            if (interval.start > cur.end) {
                result.push_back(cur);
                cur = interval;
            } else {
                cur.end = cur.end > interval.end ? cur.end : interval.end;
            }
        }
        result.push_back(cur);
        return result;
    }
};