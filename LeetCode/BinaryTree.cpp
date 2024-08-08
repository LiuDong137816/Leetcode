#include <iostream>
#include "BinaryTree.h"

namespace Solution
{
	std::vector<std::vector<int>> BinaryTree::zigzagLevelOrder(TreeNode* root)
	{
		std::vector<std::vector<int>> ires;
		if (root == nullptr)
			return ires;
		std::vector<int> ivec;
		std::vector<TreeNode*> Tvec{ root };
		int i = 1;
		while (!Tvec.empty())
		{
			std::vector<TreeNode*> Tmpvec = Tvec;
			Tvec.clear();
			ivec.clear();
			for (std::vector<TreeNode*>::reverse_iterator it = Tmpvec.rbegin(); it != Tmpvec.rend(); it++) {
				ivec.push_back((*it)->val);
				if (i % 2 == 1) {
					if ((*it)->lchild != nullptr)
						Tvec.push_back((*it)->lchild);
					if ((*it)->rchild != nullptr)
						Tvec.push_back((*it)->rchild);
				}
				else {
					if ((*it)->rchild != nullptr)
						Tvec.push_back((*it)->rchild);
					if ((*it)->lchild != nullptr)
						Tvec.push_back((*it)->lchild);
				}
			}
			++i;
			ires.push_back(ivec);
		}
		return ires;
	}

	std::vector<int> BinaryTree::preorderTraversal(TreeNode* root)
	{
		std::vector<int> ivec;
		if (nullptr != root)
			ivec.push_back(root->val);
		if (root->lchild != nullptr)
			preorderTraversal(root->lchild);
		if (root->rchild != nullptr)
			preorderTraversal(root->rchild);
		return ivec;
	}

	std::vector<int> BinaryTree::postorderTraversal(TreeNode* root)
	{
		std::vector<int> ivec;
		if (root->lchild != nullptr)
			preorderTraversal(root->lchild);
		if (root->rchild != nullptr)
			preorderTraversal(root->rchild);
		if (nullptr != root)
			ivec.push_back(root->val);
		return ivec;
	}

	void BinaryTree::rightSideView_Help(TreeNode* root, std::vector<int>& res, int level)
	{
		if (nullptr == root) {
			return;
		}
		if (res.size() == level)
			res.push_back(root->val);
		rightSideView_Help(root->rchild, res, level + 1);
		rightSideView_Help(root->lchild, res, level + 1);
	}

	std::vector<int> BinaryTree::rightSideView(TreeNode* root)
	{
		std::vector<int> res;
		rightSideView_Help(root, res, 0);
		return res;
	}

	void BinaryTree::TreeTest()
	{
		std::vector<int> ivec{ 2,7,11,15 };
		TreeNode* root;
		CreateTree(root);
		std::vector<int> res = rightSideView(root);
	}

	void BinaryTree::connect(TreeLinkNode* root)
	{
		if (nullptr == root)  return;
		TreeLinkNode* pre = root;
		TreeLinkNode* cur = nullptr;
		while (pre->left)
		{
			cur = pre;
			while (cur)
			{
				cur->left->next = cur->right;
				if (cur->next) cur->right->next = cur->next->left;
				cur = cur->next;
			}
			pre = pre->left;
		}
	}

	void BinaryTree::connect1(TreeLinkNode* root)
	{
		while (root != nullptr)
		{
			TreeLinkNode* tmpNode = new TreeLinkNode(0);
			TreeLinkNode* currNode = tmpNode;
			while (root != nullptr)
			{
				if (root->left != nullptr) {
					currNode->next = root->left;
					currNode = currNode->next;
				}
				if (root->right != nullptr) {
					currNode->next = root->right;
					currNode = currNode->next;
				}
				root = root->next;
			}
			root = tmpNode->next;
		}
	}

	void BinaryTree::CreateTree(TreeNode*& T)
	{
		int val;
		std::cin >> val;
		if (val == 0) {
			T = nullptr;
		}
		else {
			T = new TreeNode(val);
			CreateTree(T->lchild);
			CreateTree(T->rchild);
		}
	}
	void BinaryTree::PrintTree(BiTNode* T)
	{
		if (T == nullptr) {
			std::cout << " nullptr ";
		}
		else {
			std::cout << T->val << " ";
			PrintTree(T->lchild);
			PrintTree(T->rchild);
		}
	}
}