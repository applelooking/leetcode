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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> result;
        int i = 0;
        for (i = 0;i < intervals.size();++i) {
            if (newInterval.start > intervals[i].end) {
                result.push_back(intervals[i]);
                continue;
            }
            else break;
        }
        if (i == intervals.size()) {
            result.push_back(newInterval);
            return result;
        }
        Interval tmp = newInterval;
        if (intervals[i].start < newInterval.start) {
            newInterval = intervals[i];
            intervals[i] = tmp;
        }
        for (i; i < intervals.size();++i) {
            if (intervals[i].start <= newInterval.end) {
                newInterval.end = max(intervals[i].end, newInterval.end);
            } else {
                result.push_back(newInterval);
                newInterval = intervals[i];
            }
        }
        result.push_back(newInterval);
        return result;
    }
};