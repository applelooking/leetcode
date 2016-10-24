class Solution {
public:
    int find(vector<int>& father, int child) {
        if (father[child] == child) return child;
        return father[child] = find(father, father[child]);
    }
    bool validTree(int n, vector<pair<int, int>>& edges) {
        if (edges.size() != n - 1) return false;
        vector<int> father(n);
        for (int i = 0;i < n;++i) {
            father[i] = i;
        }
        for (auto edge : edges) {
            int father1 = find(father, edge.first);
            int father2 = find(father, edge.second);
            if (father1 == father2) return false;
            father[father1] = father2;
        }
        return true;
    }
};