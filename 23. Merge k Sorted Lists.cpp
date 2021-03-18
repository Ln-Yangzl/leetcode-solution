#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};
/*
struct compare {
	bool operator()(const ListNode* l, const ListNode* r) {
		return l->val > r->val;
	}
};
ListNode* mergeKLists(vector<ListNode*>& lists) { //priority_queue
	priority_queue<ListNode*, vector<ListNode*>, compare> q;
	for (auto l : lists) {
		if (l)  q.push(l);
	}
	if (q.empty())  return NULL;

	ListNode* result = q.top();
	q.pop();
	if (result->next) q.push(result->next);
	ListNode* tail = result;
	while (!q.empty()) {
		tail->next = q.top();
		q.pop();
		tail = tail->next;
		if (tail->next) q.push(tail->next);
	}
	return result;
}*/

ListNode* mergeKLists(vector<ListNode*>& lists) {
	if (lists.empty()) return NULL;
	ListNode* head = new ListNode(INT_MIN);
	ListNode* current = head;	
	while (lists.size() > 1) {
		vector<ListNode*>::iterator temp;
		int min = INT_MAX;
		for (vector<ListNode*>::iterator i = lists.begin(); i != lists.end();) {
			if (*i != NULL) {
				if ((*i)->val < min) {
					min = (*i)->val;
					temp = i;
				}
				i++;
			}
			else {
				i = lists.erase(i);
			}
		}
		if (min != INT_MAX) {
			current->next = *temp;
			current = current->next;
			*temp = (*temp)->next;
		}	
	}
	current->next = lists[0];
	head = head->next;
	return head;
}

int main() {
	int n;
	vector<ListNode*> test;
	cin >> n;
	for (int i = 0; i < n; i++) {
		ListNode* head = NULL;
		ListNode* current = NULL;
		while (true) {
			int temp;
			cin >> temp;
			if (temp) {
				if (!current) {
					head = current = new ListNode(temp);
				}
				else {
					current->next = new ListNode(temp);
				}
			}
			else break;
		}
		test.push_back(head);
	}
	ListNode* result = mergeKLists(test);
	while (result) {
		cout << result->val << " ";
		result = result->next;
	}
	return 0;
}