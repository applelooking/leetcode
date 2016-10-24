class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> mapping(numCourses, vector<int>());
        vector<int> in_degree(numCourses, 0);
        for (auto pre : prerequisites) {
            mapping[pre.second].push_back(pre.first);
            ++in_degree[pre.first];
        }
        vector<int> result;
        queue<int> q;
        for (int i = 0;i < in_degree.size();++i) {
            if (in_degree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            result.push_back(cur);
            for (auto course : mapping[cur]) {
                if (--in_degree[course] == 0) {
                    q.push(course);
                } 
            }
        }
        if (result.size() == numCourses) return result;
        else return vector<int>();
    }
};