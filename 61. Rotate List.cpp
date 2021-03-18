#include <iostream>
#include <fstream>

using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
ListNode* rotateRight(ListNode* head, int k) {
    if (head == NULL || head->next == NULL || k == 0) return head;
    int len = 0;
    ListNode* end = head, *temp = end;
    while (end != NULL) {
        len++;
        temp = end;
        end = end->next;
    }
    end = temp;
    k %= len;
    if (k == 0) return head;
    int edge = len - k;
    ListNode* p = head;
    for (int i = 0; i < edge - 1; i++) {
        p = p->next;
    }
    end->next = head;
    head = p->next;
    p->next = NULL;
    return head;
}