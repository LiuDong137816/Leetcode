#include <vector>
#include <stack>
#include "SingleList.h"

namespace Solution{
	
	Node* List::Create()
	{
		int n = 0;
		Node* head, * p1, * p2;
		p1 = p2 = new Node(0);
		//p1 = p2 = new Node;
		std::cin >> p1->data;
		head = nullptr;
		while (p1->data != 0)
		{
			if (n == 0)
			{
				head = p1;
			}
			else
				p2->next = p1;
			p2 = p1;
			//p1 = new Node;
			p1 = new Node(0);
			std::cin >> p1->data;
			n++;
		}
		p2->next = nullptr;
		return head;
	}

	Node* List::reverseBetween(Node* head, int m, int n)
	{
		Node* tmpNode = head;
		std::vector<int> ivec;
		for (int i = 1; i < m; i++) {
			tmpNode = tmpNode->next;
		}
		Node* tmpNode2 = tmpNode;
		for (int j = m; j <= n; j++) {
			ivec.push_back(tmpNode->data);
			tmpNode = tmpNode->next;
		}
		for (int k = n - m; k >= 0; k--) {
			tmpNode2->data = ivec[k];
			tmpNode2 = tmpNode2->next;
		}
		return head;
	}
	void List::insert(Node* head, int p, int x)
	{
		Node* tmp = head;//for循环是为了防止插入位置超出了链表长度
		for (int i = 0; i < p; i++)
		{
			if (tmp == nullptr)
				return;
			if (i < p - 1)
				tmp = tmp->next;
		}
		Node* tmp2 = new Node(0);
		tmp2->data = x;
		tmp2->next = tmp->next;
		tmp->next = tmp2;
	}

	void List::PrintList(Node* listNode)
	{
		for (; listNode != nullptr; listNode = listNode->next) 
		{
			std::cout << listNode->data << " ";
		}
	}

	Node* List::deleteDuplicates(Node* head)
	{
		if (head == nullptr || head->next == nullptr)
			return head;
		Node* res = head;
		Node* p = head;
		while (p->next != nullptr) {
			if (p->data == p->next->data) {
				p->next = p->next->next;
				continue;
			}
			p = p->next;
		}
		return res;
	}
	Node* List::reverseList(Node* head)
	{
		std::stack<int> stk;
		while (head)
		{
			stk.push(head->data);
			head = head->next;
		}
		Node* res = new Node(0);
		Node* CurNode = res;
		while (!stk.empty())
		{
			Node* tmpNode = new Node(stk.top());
			stk.pop();
			CurNode->next = tmpNode;
			CurNode = CurNode->next;
		}
		return res->next;
	}
}