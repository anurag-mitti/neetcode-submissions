class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode* dummy = new ListNode(0, head);

        ListNode* b4l = dummy;
        for (int i = 1; i < left; i++) {
            b4l = b4l->next;
        }
        
        ListNode* l = b4l->next; 

        ListNode* rNode = l;
        for (int i = left; i < right; i++) {
            rNode = rNode->next;
        }
        ListNode* ar = rNode->next;

        ListNode* prev = l;
        ListNode* cur = l->next;
        while (cur != ar) {
            ListNode* temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }

        b4l->next = rNode;
        l->next = ar;

        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};