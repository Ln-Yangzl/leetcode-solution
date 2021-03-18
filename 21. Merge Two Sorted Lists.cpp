#include <iostream>

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	ListNode* head = new ListNode(INT_MIN);
	ListNode* current = head;
	while (l1 != nullptr && l2 != nullptr) {
		if (l1->val > l2->val) {
			current->next = l2;
			l2 = l2->next;
		}
		else {
			current->next = l1;
			l1 = l1->next;
		}
		current = current->next;
	}
	if (l1 == nullptr) current->next = l2;
	else if (l2 == nullptr) current->next = l1;
	head = head->next;
	return head;
}