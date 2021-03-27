#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* deleteDuplicates(ListNode* head) {
	ListNode* cur = head;
	while (cur != nullptr) {
		while (cur->next && cur->val == cur->next->val) {
			cur->next = cur->next->next;
		}
		cur = cur->next;
	}
	return head;
}
