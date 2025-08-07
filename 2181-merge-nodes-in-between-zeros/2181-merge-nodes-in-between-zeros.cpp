class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        int sum = 0;
        head = head->next;  
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* ans = NULL;

        while (curr != NULL) {
            if (curr->val == 0) {
                ListNode* temp = new ListNode(sum);
                sum = 0;
                if (ans == NULL) {
                    ans = temp;
                    prev = temp;
                } else {
                    prev->next = temp;
                    prev = prev->next;
                }
            } else {
                sum += curr->val;
            }
            curr = curr->next;
        }

        return ans;
    }
};
