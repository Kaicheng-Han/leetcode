/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    struct Status {
        int val;
        ListNode* ptr;
        bool operator < (const Status& rhs) const {
            return val > rhs.val;
        }
    };

    priority_queue<Status> pq;

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode{0, nullptr};
        ListNode* tail = head;
        for(auto node : lists) {
            if(node) {
                pq.push({node->val, node});
            }
        }
        while(!pq.empty()) {
            auto f = pq.top();
            pq.pop();
            tail->next = f.ptr;
            tail = tail->next;
            if(f.ptr->next) {
                pq.push({f.ptr->next->val, f.ptr->next});
            }
        }
        return head->next;
    }
};