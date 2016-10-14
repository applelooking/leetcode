/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* result = new ListNode(0);
        ListNode* ptr = result;
        typedef pair<int, ListNode*> node;
        priority_queue<node, vector<node>, greater<node>> pq;
        for (auto list : lists) {
            if (list != NULL) {
                pq.push({list->val, list});
            }
        }
        while (!pq.empty()) {
            auto first = pq.top();
            ptr->next = first.second;
            ptr = ptr->next;
            pq.pop();
            if (ptr->next) {
                pq.push({ptr->next->val, ptr->next});
            }
        }
        return result->next;
    }
};