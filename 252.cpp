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
private:
    static bool compare(const Interval& first, const Interval& second) {
        return first.start < second.start;
    }
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        if (intervals.size() <= 1) return true;
        for (int i = 1;i < intervals.size();++i) {
            if (intervals[i].start < intervals[i - 1].end) return false;
        }
        return true;
    }
};