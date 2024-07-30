#pragma once
#include <iostream>

namespace Solution {

	struct Node
	{
		int data;//数据域
		struct Node* next;//指针域
		Node(int x) : data(x), next(nullptr) {}
	};
	using Node = struct Node;

	class List
	{
	public:
		Node* reverseBetween(Node* head, int m, int n);
		void insert(Node* head, int p, int x);
		void PrintList(Node* listNode);
		Node* deleteDuplicates(Node* head);
		Node* reverseList(Node* head);
	private:
		Node* Create();
	};
}

