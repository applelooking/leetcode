class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int result = 0;
        for (int h = 1; h <= citations.size();++h) {
            if (citations[citations.size() - h] >= h){
                result = h;
            }
        }
        return result;
    }
};