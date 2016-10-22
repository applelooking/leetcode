/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
private:
    vector<int> result; 
    int pointer;
public:
    void DFS(vector<NestedInteger> &nestedList) {
        for (auto integer : nestedList) {
            if (integer.isInteger()) {
                result.push_back(integer.getInteger());
            } else {
                DFS(integer.getList());
            }
        }
    }
    NestedIterator(vector<NestedInteger> &nestedList) {
        DFS(nestedList);
        pointer = 0;
    }

    int next() {
        return result[pointer++];
    }

    bool hasNext() {
        return pointer < result.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */