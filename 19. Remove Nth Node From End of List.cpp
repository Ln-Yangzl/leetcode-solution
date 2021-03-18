#include <iostream>

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
	ListNode* tail = head, * current = head, * former = head;
	for (int i = n; i > 0; i--) {
		tail = tail->next;
	}
	while (tail != nullptr) {
		former = current;
		current = current->next;
		tail = tail->next;
	}
	if (head == current) {
		head = current->next;
	}
	else {
		former->next = current->next;
		delete current;
	}
	return head;
}

int main() {
	return 0;
}