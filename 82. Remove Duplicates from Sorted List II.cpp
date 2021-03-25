#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    // add void head
    ListNode* pre = new ListNode(INT_MIN, head);
    head = pre;
    ListNode* cur = pre->next, * nxt = pre->next == nullptr ? nullptr : pre->next->next;
    bool flag = false;
    while (nxt != nullptr) {
        if (cur->val == nxt->val) {
            flag = true;
        }
        else if (flag) {
            pre->next = nxt;
            flag = false;
        }
        else {
            pre = pre->next;
        }
        cur = cur->next;
        nxt = nxt->next;
    }
    if (flag) {
        pre->next = nxt;
    }
    return head->next;
}

// use a small triky to make the code simpler and faster
ListNode* deleteDuplicates(ListNode* head) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* cur = dummy;
    int duplicate;
    while (cur->next && cur->next->next) {
        if (cur->next->val == cur->next->next->val) {
            duplicate = cur->next->val;
            while (cur->next && cur->next->val == duplicate) {
                cur->next = cur->next->next;
            }
        }
        else {
            cur = cur->next;
        }
    }
    return dummy->next;
}