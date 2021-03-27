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


ListNode* partition(ListNode* head, int x) {
    if (head == nullptr) return head;
    head = new ListNode(INT_MIN, head);
    ListNode* tail = head;
    int count = 0;
    // find the tail and the total num of the list
    while (tail->next != nullptr) {
        tail = tail->next;
        count++;
    }
    ListNode* cur = head, *end = tail;
    while (cur->next != tail) {
        if (cur->next->val < x) cur = cur->next;
        else {
            end->next = cur->next;
            cur->next = cur->next->next;
            end = end->next;
            end->next = nullptr;
        }
    }
    if (cur->next->val >= x) {
        end->next = cur->next;
        cur->next = cur->next->next;
        end = end->next;
        end->next = nullptr;
    }
    return head->next;
}