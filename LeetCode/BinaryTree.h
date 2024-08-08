#pragma once
#include <vector>

namespace Solution
{
	class BinaryTree
	{
	public:
		typedef struct BiTNode {
			int val;
			BiTNode* lchild;
			BiTNode* rchild;
			BiTNode(int x) : val(x), lchild(nullptr), rchild(nullptr) {}
		}TreeNode;

		struct TreeLinkNode {
			int val;
			TreeLinkNode* left, * right, * next;
			TreeLinkNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
		};

		std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root);
		std::vector<int> preorderTraversal(TreeNode* root);
		std::vector<int> postorderTraversal(TreeNode* root);
		void rightSideView_Help(TreeNode* root, std::vector<int>& res, int level);
		std::vector<int> rightSideView(TreeNode* root);
		void TreeTest();
		void connect(TreeLinkNode* root);
		void connect1(TreeLinkNode* root);
	private:
		void CreateTree(TreeNode*& T);
		void PrintTree(BiTNode* T);
	};
}