#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k > 1) for (auto pp = &head; *pp;) pp = reverse(pp, k);
        return head;
    }
private:
    ListNode** reverse(ListNode** pphead, int k) {
        auto ppnew = &((*pphead)->next);
        for (int kr = 1; kr < k; kr++) {
            if (!*ppnew) return reverse(pphead, kr);
            auto pnext = (*ppnew)->next;
            (*ppnew)->next = *pphead;
            *pphead = *ppnew;
            *ppnew = pnext;
        }
        return ppnew;
    }
};

ListNode* reverseKGroup(ListNode* head, int k) {
    if (head == NULL || k == 1)
        return head;
    ListNode* preheader = new ListNode(-1);
    preheader->next = head;
    ListNode* curr = preheader, * next = NULL, * prev = preheader;
    int num = 0;
    while (curr = curr->next)
        num++;
    while (num >= k) {
        curr = prev->next;
        next = curr->next;
        for (int i = 1; i < k; i++) {
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
            next = curr->next;
        }
        prev = curr;
        num -= k;
    }
    return preheader->next;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    if (head == NULL) return NULL;
    if (k == 1) return head;
    ListNode* current = head, * current_nxt = head->next;
    ListNode* previous = new ListNode(INT_MIN, head);
    head = previous;
    ListNode* tail = head->next;
    for (int i = 0; i < k; i++) {
        tail = tail->next;
    }
    ListNode* tail_nxt = tail;
    bool flag = true;
    while (flag) {
        ListNode* start = current;
        tail_nxt = tail_nxt ? tail->next : NULL;
        for (int i = 1; i < k; i++) {
            ListNode* temp = current_nxt->next;
            current_nxt->next = current;
            current = current_nxt;
            current_nxt = temp;
            if (tail_nxt) {
                tail_nxt = tail_nxt->next;
            }
            else {
                flag = false;
            }
        }
        previous->next = current;
        start->next = tail;
        previous = start;
        tail = tail_nxt;
        current = current_nxt;
        current_nxt = current_nxt ? current_nxt->next : NULL;
    }
    return head->next;
}