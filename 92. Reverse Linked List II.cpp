#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// the same solution with respect to reverse nodes in k group
ListNode* reverseBetween(ListNode* head, int left, int right) {
	head = new ListNode(INT_MIN, head);
	ListNode* cur = head;
	int count = 1;
	while (count < left) {
		cur = cur->next;
		count++;
	}
	ListNode* prev = cur, *next = cur->next->next;
	cur = cur->next;
	while (count < right) {
		cur->next = next->next;
		next->next = prev->next;
		prev->next = next;
		next = cur->next;
		count++;
	}
	return head->next;
}