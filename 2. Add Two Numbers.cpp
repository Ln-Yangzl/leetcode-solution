#include"ListNode.h"
#include<iostream>

using std::cin;		using std::cout;
using std::endl;


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{
	ListNode* ans = new ListNode(0), * ans_ptr = ans;
	int flag = 0, t1 = l1->val, t2 = l2->val;	//flag��Ϊ��λ��־
	
	while (1)
	{
		ans_ptr->val = t1 + t2 + flag;	//���Ͽ��ܵĽ�λ
		flag = 0;
		if (ans_ptr->val >= 10)
		{
			ans_ptr->val -= 10;
			flag = 1;	//��Ҫ��λ
		}
		if (l1->next == NULL && l2->next == NULL)
			break;
		if (l1->next)
		{
			l1 = l1->next;
			t1 = l1->val;
		}
		else
			t1 = 0;
		if (l2->next)
		{
			l2 = l2->next;
			t2 = l2->val;
		}
		else
			t2 = 0;
		ans_ptr->next = new ListNode;
		ans_ptr = ans_ptr->next;
	}
	if (flag)
	{
		ans_ptr->next = new ListNode;
		ans_ptr->next->val = flag;
	}
	return ans;
}

int main()
{
	return 0;
}